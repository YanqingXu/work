-- 需要包含的lua文件
require "xf.logic.network.message.receive_message"
require "xf.logic.network.proxy.SocketProxy"
require "xf.logic.network.proxy.MsgCategory"
require "xf.logic.utils.StringUtils"
require "xf.base.database.language_data"
require "xf.base.local.zh-CN.language"
require "xf.logic.userdata.UserDefaultDataHelper"
require "xf.logic.globalData.EventNames"
require "xf.logic.helper.NotifyHelper"
require "xf.logic.network.entity.target"
require "xf.base.database.event_data"
require "xf.logic.utils.RichTextUtils"
-- require "xf.logic.userdata.UserDefaultDataDefination"

-- 全局变量，从老的GameData里面分离出来
ServerList={
    all={},
    }


SdkAccountInfo = {
    
    id = "",
    name = "",
    token = "",
}

PlayerList=nil
loginscenexx = nil

HaveReloaded = false
AgreementChecked = true
Player = {
AID = 0,
mName = "",
mGhostGender = "",
mGhostJop = "",
mHp = "",
mMp = "",
mMaxHp = "",
mMaxMp = "",
mLevel = "",
}
LoginCrossServer = nil
IsBeKicked = false
require "xf.logic.ui.Login.LoginSmallHelper"
require "xf.logic.ui.Login.LoginSmallProxy"


-- 需要用到的界面类
ServerChoose = require("xf.logic.ui.Login.ServerChoose").getInstance()
EnterUI = require("xf.logic.ui.Login.Enter").getInstance()
NoticeUI = require("xf.logic.ui.Login.Notice").getInstance()
LoginLoadingPanel = require("xf.logic.ui.Login.LoginLoading").getInstance()
ServerEnter = require("xf.logic.ui.Login.ServerEnter").getInstance()
AuthUI = require("xf.logic.ui.Login.Auth").getInstance()
AgreementUI = require("xf.logic.ui.Login.Agreement").getInstance()
RightAgeUI = require("xf.logic.ui.Login.RightAgeTips").getInstance()