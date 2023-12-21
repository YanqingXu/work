#include "Service.h"
#include <boost/asio.hpp>

Service::Service() :
    m_io_loop(new boost::asio::io_service),
    m_io_work(new boost::asio::io_service::work(*(boost::asio::io_service*)m_io_loop)),
    m_running(false),
    m_queue_counter(0)
{
}

Service::~Service()
{
    delete (boost::asio::io_service::work*)m_io_work;
    delete (boost::asio::io_service*)m_io_loop;
}

void Service::start()
{
    m_running = true;
    m_thread = std::thread(&Service::run, this);
}

void Service::stop()
{
    m_running = false;
    ((boost::asio::io_service*)m_io_loop)->stop();
    m_thread.join();
}

void Service::run()
{
    onStart();
    ((boost::asio::io_service*)m_io_loop)->run();
    onStop();
}

void Service::postMessage(Message* message)
{
    ((boost::asio::io_service*)m_io_loop)->post([this, message]() {
        dispatchMessage(message);
    });
}

void Service::dispatchMessage(Message* message)
{
    int key = (message->category << 16) | message->id;
    auto it = m_handler_map.find(key);
    if (it != m_handler_map.end()) {
        for (auto handler : it->second) {
            handler->handle_message(handler->handler, message);
        }
    }
}

Module* Service::getModule(const char* name)
{
    auto it = m_module_map.find(name);
    if (it != m_module_map.end()) {
        return it->second;
    }
    return nullptr;  // 如果模块不存在则返回nullptr
}

void Service::onUpdate(int elapse)
{
    for (auto module : m_modules) {
        module->update(elapse);
    }
}

void Service::onStart()
{
    for (auto module : m_modules) {
        module->start();
    }
}

void Service::onStop()
{
    for (auto module : m_modules) {
        module->stop();
    }
}

void Service::onMessage(Message* message) {
    if (message == nullptr) {
        return;
    }

    int category = message->getCategory();
    int id = message->getID();
    int key = (category << 16) | id;

    auto it = m_handler_map.find(key);
    if (it != m_handler_map.end()) {
        for (auto& handler : it->second) {
            handler->handle_message(handler->handler, message);
        }
    }
}

