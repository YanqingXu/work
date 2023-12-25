
if not Guild then
	Guild = {}
end

--公会默认公告
Guild.defaultNotice = gdSvrLanguage[144].text

--公会清理间隔(毫秒)
Guild.timeinterval = 1800000

local explore_list = {}

local function get_last_week()
	local cur_time = os.time()
	local cur_date = os.date("*t", cur_time)
	cur_date.wday = cur_date.wday - 1
	if cur_date.wday == 0 then
		cur_date.wday = 7
	end

	local cur_week = os.time({year = cur_date.year, month = cur_date.month, day = cur_date.day, hour = 0, min = 0, sec = 0}) - ((cur_date.wday - 1) * 24 * 3600)

	return cur_week - (7 * 24 * 3600)
end

function Guild.checkVersion()
	-- 检查公会商城版本
	-- local guildShop = gdShops[18]
	-- local oldVersion = _G.getWorldDataX(WORLD_PROP_GUILD_SHOP_VERSION)
	-- local curVersion = guildShop.version or oldVersion
	-- if curVersion ~= oldVersion then
	-- 	_G.delShopItem()
	-- 	_G.setWorldDataX(WORLD_PROP_GUILD_SHOP_VERSION, curVersion)
 	-- 	_G.saveWorldData(WORLD_PROP_GUILD_SHOP_VERSION)
	-- end
end

function Guild.loadGuildShopData()
	--[[local shopdata = gdShops[18]

	if not shopdata then
		log.error("Guild.loadGuildShopData : No Shop Data ShopID 18")
		return
	end

	for k, v in pairs(shopdata.items) do
		_G.addShopItem(k,v.sid,v.price.new or 0, v.level)
	end
	log.info("Guild.loadGuildShopData load finish!!!!!!")]]
end

function Guild.GetGuildLevelInfo(contribution)
	local level = 1
	for k,v in ipairs(gdGuildLevelDatas) do
		level = k
		if ( contribution < v.moneymax) then
			local guilddata = gdGuildLevelDatas[k-1]
			if (guilddata) then
				return guilddata.level + 1,guilddata.maxmember
			else
				return 1,15
			end
		end
	end
	local guilddata = gdGuildLevelDatas[level]
	if (guilddata) then
		return guilddata.level,guilddata.maxmember
	else
		return 1,15
	end

end

local donateData = {
	[THINGS_COIN] = {
		[1] = {cost=20000, contribute=1, gmoney=10000,},
		[2] = {cost=100000, contribute=5, gmoney=50000,},
		[3] = {cost=1000000, contribute=50, gmoney=500000,},
	},
	[THINGS_LINGFU] = {
		[1] = {cost=50, contribute=50, gmoney=500000,},
		[2] = {cost=500, contribute=500, gmoney=5000000,},
		[3] = {cost=1000, contribute=1000, gmoney=10000000,},
	},
}
-- 行会捐赠
function Guild.getDonateData(type, index)
	local data = donateData[type]
	if data then
		local subdata = data[index]
		if subdata then
			return subdata.gmoney, subdata.contribute, subdata.cost
		end
	end
	return 0, 0, 0
end

function Guild.GetReward(job)
	local sd = gdGuildJobReward[job]
	if not sd then
		return
	end
	return sd.reward,sd.count
end

function Guild.GetDefaultNickname(post)
	if post == GUILD_POST_MASTER then
        return gdCliLanguage[898].text
    elseif post == GUILD_POST_SECOND_MASTER then
        return gdCliLanguage[30452].text
    elseif post == GUILD_POST_ELDER then
        return gdCliLanguage[30453].text
    elseif post == GUILD_POST_PROTECTOR then
        return gdCliLanguage[30454].text
    elseif post == GUILD_POST_ELITE then
        return gdCliLanguage[30455].text
    else
        return gdCliLanguage[30456].text
    end
end

function Guild.preCreateGuild(entity)
	if entity:hasItem(80014, 1, BAG_TYPE_PLAYER) ~= true then
		return ERROR_NOT_ENOUGH_ITEM
	end
	if Entity.getCapital(entity, ITEM_INGOT_ALL) < 3000 then
		return ERROR_NOT_ENOUGH_BOUND_INGOT
	end
	entity:rmvItem(80014, 1,BAG_TYPE_PLAYER,OP_GUILD_CREATE)
	Entity.useCapital(entity,ITEM_INGOT_ALL, 3000,OP_GUILD_CREATE)
	return SUCCESS
end

function Guild.refreshShop(guild)
	-- local glvl = guild:getProp(GUILD_PROP_LEVEL)
	-- local guildShop = gdShops[18]
	-- local events = {}

	-- function randomItem( items )
	-- 	local totalRate = 0
	-- 	for idx=1, #items do
	-- 		totalRate = totalRate + items[idx].weight
	-- 	end

	-- 	local ret = 0
	-- 	local rolledItems = {}
	-- 	local cnt = 1
	-- 	if items and items[1] then 
	-- 		cnt = items[1].gridCnt 
	-- 	end

	-- 	if #items > cnt then
	-- 		for idx=1, cnt do
	-- 			ret = 0
	-- 			local rate = math.random(totalRate)
	-- 			for i = 1, #items do
	-- 				if not rolledItems[i] then
	-- 					ret = ret + items[i].weight
	-- 					if ret >= rate then
	-- 						rolledItems[i] = 1
	-- 						totalRate = totalRate - items[i].weight
	-- 						break
	-- 					end
	-- 				end
	-- 			end
	-- 		end
	-- 	else
	-- 		for idx=1, #items do
	-- 			rolledItems[idx] = 1
	-- 		end
	-- 	end

	-- 	for k, v in pairs(rolledItems) do
	-- 		guild:addShopItem(items[k].sid)
	-- 		table.insert(events, items[k].eventId)
	-- 	end
	-- end
	-- -- 按等级分组
	-- local lvl_Items = {}
	-- for i=1, guildShop.itemcnt do
	-- 	local lvl = guildShop.items[i].gLvl
	-- 	if not lvl_Items[lvl] then
	-- 		lvl_Items[lvl] = {}
	-- 	end

	-- 	table.insert(lvl_Items[lvl], guildShop.items[i])
	-- end
	
	-- -- 随机物品
	-- for i=1, #lvl_Items do
	-- 	randomItem(lvl_Items[i])
	-- end

	-- -- 同步限购次数
	-- guild:forEach(
	-- 	function(entity)
	-- 		if entity then
	-- 			--for k, v in pairs(events) do
	-- 			for v = EVENT_GHSD1, EVENT_GHSD_END do
	-- 				entity:syncEventData(v)
	-- 				entity:saveEventData(v)
	-- 			end
	-- 		end
	-- 	end
	-- )
	-- -- 刷新商城物品
	-- guild:syncShopItems()
end

function Guild.onCreate(guild)
	GCZ.onGuildCreate(guild)

	-- 公会商店物品刷新
	Guild.refreshShop(guild)
end

function Guild.onCreateGuild(guild, player)
	if not guild or not player then
		return
	end
	--Gift.CheckGuildStaringReward(guild, player)
	
	-- 首次创建行会会
	if _G.getWorldDataX(WORLD_PROP_FIRSTBLOOD_BOSS_DATA) == 0 then
		_G.setWorldDataX(WORLD_PROP_FIRSTBLOOD_BOSS_DATA, os.time())
		_G.saveWorldData(WORLD_PROP_FIRSTBLOOD_BOSS_DATA)
		_G.syncWorldData(WORLD_PROP_FIRSTBLOOD_BOSS_DATA)
	end
end

-- 生成红包的规则
function Guild.randomRed(entity, maxgold, maxcount, curgold, curcount, red_type, desc)
	if curcount > maxcount or curgold > maxgold then
		return ERROR_GUILD_NOT_ENOUGH_GUILD_RED, 0
	end

	if red_type == GUILD_RED_PACKAGE_ACTIVITY then
		-- 这个红包是否有指定某些玩家
		local able = false
		if desc and #desc > 0 then
			local arr = Split(desc, "_")
			if #arr >= 2 then
				local eventId = tonumber(arr[1])
				local arrPids = Split(arr[2], ";")
				for k, v in pairs(arrPids) do
					local pid = tonumber(v)
					if entity:getGlobalID() == pid then
						able = true
						break
					end
				end
			end
		else
			able = true
		end
		if not able then
			return ERROR_GUILD_EVENT_UNJOIN, 0
		end
	end

	local gold = maxgold - curgold
	if maxcount - curcount > 1 then
		-- 上限
		local upgold = math.floor((maxgold - curgold) / (maxcount - curcount)) * 2
		gold = math.random(1, upgold - 1)
	end

	if red_type == GUILD_RED_PACKAGE_ACTIVITY then
		entity:addIngot(gold, OP_GUILD_GET_RED)
	else
		entity:addLingFu(gold, OP_GUILD_GET_RED)
	end

	return SUCCESS, gold
end

--返回物品的装备贡献值
function Guild.getGxValue(iid)
	local item = gdItems[iid]
	if item == nil then
		return 0
	end

	return item.rec_gx or 0
end

--返回剩余红包
function Guild.backRed(playerid, leftgold)
	--sendMail(name, "剩余红包返还", "", {static_id=3, count=leftgold})
     sendMail(playerid, gdSvrLanguage[11].text, "", {static_id=3, count=leftgold})
end

function Guild.checkGuildCD(entity)
	--local leave_time = entity:getProp(ENTITY_PROP_LEAVE_GUILD_TIME)
	--if os.time() - leave_time < 3600*2 then
	--	return ERROR_GUILD_IN_LEAVE_TIME
	--end
	-- 游戏猫渠道需要判断玩家cd
	-- local channel_id = entity:getProp(ENTITY_PROP_CHANNEL_ID)
	-- if _G.getChannelProp(channel_id, CHANNEL_PROP_GUILD_JOIN_TIME_LIMIT) > 0 then
	-- 	-- 离开公会**小时内不能申请加入别的公会
	-- 	if isSwitchEnabled(SWITCH_GUILD_JOIN_CD) then
			
	-- 	end
	-- end
	
	return SUCCESS
end
--能否申请加入行会
function Guild.canApplyToJoinGuild(entity,guild_id)
	if not Event.isGuildActivityTime(entity, true) then
		return ERROR_OVER_GUILD_OPERATOR_LIMIT
	end
	
	if entity:getProp(ENTITY_PROP_GUILD_ID) > 0 then
		--玩家已经加入了某个行会
		return ERROR_GUILD_HAS_GUILD
	end

	local guild = _G.getGuild(guild_id)
	if not guild then
		--行会不存在
		return ERROR_GUILD_NOT_EXIST
	end

	-- 公会cd
	if Guild.checkGuildCD(entity) ~= SUCCESS then
		return Guild.checkGuildCD(entity)
	end
	
	--检查玩家等级
	local level = entity:getLevel()
	local autolvl = guild:getProp(GUILD_PROP_AUTOADD_LEVEL)
	if autolvl >= 1 and autolvl<= 999 then
		if level < autolvl then
			return ERROR_NOT_ENOUGH_LEVEL
		end
	end

	local nowplayercnt = guild:getMemberCount()
	local lvl = guild:getProp(GUILD_PROP_LEVEL)
	local gdata = gdGuildLevelDatas[lvl].guildNum
	if gdata then
		if gdata <= nowplayercnt then
			return ERROR_GUILD_MAX_MEMBER
		end
	else
		return ERROR_UNKNOWN
	end

	return SUCCESS
end

--申请加入行会
function Guild.applyToJoinGuild(entity, guild_id)
	local result =  Guild.canApplyToJoinGuild(entity,guild_id)
	if result == SUCCESS then
		local guild = _G.getGuild(guild_id)
		if guild then
		  if guild:InApplicaition(entity) == 1 then
			return ERROR_GUILD_REAPP
		  end
		  return guild:addApplication(entity)
		end
		return ERROR_GUILD_NOT_EXIST
	else
		return result
	end
end

if not lastGuildUpdate then
	lastGuildUpdate = 0
end

function Guild.getUpdateData()
	local oldtimetable = nil
	if lastGuildUpdate > 0 then
		oldtimetable = os.date("*t",lastGuildUpdate)
	end
	local timetable = os.date("*t")

	local guilddownmoney = false
	local guildresetdata = false
	local levelmoney = 5000

	if oldtimetable and oldtimetable.wday ~= timetable.wday then
		local week = timetable.wday - 1
		if week == 0 then -- 周日
			guilddownmoney = true
		end
		guildresetdata = true
	end
	lastGuildUpdate = os.time()

	return guilddownmoney,guildresetdata,levelmoney
end

function Guild.PlayerLogin(entity, guild)
	local member = guild:getMemberByPlayerID(entity:getGlobalID())
	if member then
		if entity:getProp(ENTITY_PROP_GID_TO_SDK) ~= guild:getID() then
			entity:setProp(ENTITY_PROP_GID_TO_SDK, guild:getID())
			entity:saveProp(ENTITY_PROP_GID_TO_SDK)
			entity:svrToClient(FUNC_ADD_GUILD_TO_SDK, guild:getID(), 0, 0, guild:getGuildName()) --加入行会上报sdk
		end
	end
end

function Guild.initOneGuild(guild)

end

function Guild.onInit()
	_G.forEachGuild(Guild.initOneGuild)
end

function Guild.syncGuildKick(entity)
	entity:sendFuncMsg(FUNC_KICK_FROM_GUILD)
end

function Guild.isMemberFull(lvl, membercnt)
	local sd = gdGuildLevelDatas[lvl]
	if sd then
		return membercnt >= sd.guildNum
	end
	return true
end

-- 成员加入
function Guild.onAddMember(guild, pid)
	local gid = guild:getID()
	local gname = guild:getGuildName()
	local entity = _G.getPlayer(pid)	
	if entity then
		Quest.CheckBranchLineQuestIsComplete(entity, BRANCHLIINE_ADD_GUILD, 1)
		local guild_level = guild:getProp(GUILD_PROP_LEVEL)
		local guildInfo = gdGuildLevelDatas[guild_level]
		if guildInfo then
			if not entity:hasGene(guildInfo.geneId) then
				entity:addGene(guildInfo.geneId)
			end
		end
	end
end

-- 成员退出
function Guild.onRmvMember(guild, pid)
	local entity = _G.getPlayer(pid)	
	if entity then
		local guild_level = guild:getProp(GUILD_PROP_LEVEL)
		local guildInfo = gdGuildLevelDatas[guild_level]
		if guildInfo then
			if entity:hasGene(guildInfo.geneId) then
				entity:rmvGene(guildInfo.geneId)
			end
		end
	end
end

-- 行会光环

function Guild.open_guild_buff(guild, entity, guild_buff_id)
	if guild:getID() ~= entity:getProp(ENTITY_PROP_GUILD_ID) then
		return ERROR_GUILD_NO_GUILD
	end

	local guild_buff_info = gdGuildGuanghuan[guild_buff_id]
	if guild_buff_info == nil then
		log.error("Guild Buff Config Missing!")
		return ERROR_SCRIPT
	end

	-- 仅会长和副会长可开启
	local post = entity:getProp(ENTITY_PROP_GUILD_POST)
	if post ~= GUILD_POST_MASTER and post ~= GUILD_POST_SECOND_MASTER then
		return ERROR_GUILD_NOT_MASTER
	end

	-- 行会资金是否足够
	local guild_money = guild:getProp(GUILD_PROP_MONEY)
	if guild_money < guild_buff_info.cost then
		return ERROR_GUILD_NOT_ENOUGH_MONEY
	end

	-- 开启光环
	guild:setProp(GUILD_PROP_MONEY, guild_money - guild_buff_info.cost)
	guild:saveProp(GUILD_PROP_MONEY)
	guild:syncProp(GUILD_PROP_MONEY)

	guild:forEach(
		function(entity)
			entity:addGene(guild_buff_info.gene_id)
		end
	)

	return SUCCESS
end

function Guild.invite(guild, entity, target, iscustomfriend)
	if not guild then
		return ERROR_GUILD_NO_GUILD
	end

	if not entity or not target then
		return ERROR_INVALID_ENTITY
	end

	if guild:getID() ~= entity:getProp(ENTITY_PROP_GUILD_ID) then
		return ERROR_GUILD_NO_GUILD
	end

	-- 仅会长和副会长
	-- if not iscustomfriend then
	-- 	local post = entity:getProp(ENTITY_PROP_GUILD_POST)
	-- 	if post ~= GUILD_POST_MASTER and 
	-- 		post ~= GUILD_POST_SECOND_MASTER and 
	-- 		post ~= GUILD_POST_ELDER then
	-- 		return ERROR_GUILD_AUTHORITY
	-- 	end
	-- end
	if Guild.isMemberFull(guild:getProp(GUILD_PROP_LEVEL), guild:getMemberCount()) then
		return ERROR_GUILD_MAX_MEMBER
	end

	local level = target:getLevel()
	if level < 20 then
		return ERROR_SOCIAL_TARGET_LEVEL
	end

	if target:getProp(ENTITY_PROP_GUILD_ID) > 0 then
		return ERROR_GUILD_HAS_GUILD
	end

	if not target:isAlive() then
		return ERROR_INVALID_ENTITY
	end

	--公会cd
	if Guild.checkGuildCD(target) ~= SUCCESS then
		return Guild.checkGuildCD(target)
	end
	local guildID = guild:getID()
	local strInvates = target:getStringProp(ENTITY_STRPROP_GUILD_INVITE_DATA)
	local list = Split(strInvates, ";")
	for i,v in ipairs(list) do
		if list[i] and  list[i]~= "" then
			local data = Split(list[i],"|")
			local id = tonumber(data[1])
			if id == guildID then
				return ERROR_GUILD_REAPP
			end
		end
	end
	local invateNum =  #list
	if invateNum >= 10 then
		return ERROR_GUILD_INVAGE_FULL
	end
	if strInvates == "" then
        strInvates = strInvates .. guildID.."|"..entity:getName()
    else
        strInvates = strInvates .. ";" .. guildID.."|"..entity:getName()
	end
	target:setStringProp(ENTITY_STRPROP_GUILD_INVITE_DATA, strInvates)
	target:saveStringProp(ENTITY_STRPROP_GUILD_INVITE_DATA)
	target:syncStringProp(ENTITY_STRPROP_GUILD_INVITE_DATA)

	return SUCCESS
end
--拒绝邀请
function Guild.delInviteData(guild_id,player)
	if player == nil  then
		return
	end

	local newInvites = ""
	local strInvates = player:getStringProp(ENTITY_STRPROP_GUILD_INVITE_DATA)
	local list = Split(strInvates, ";")
	for i,v in ipairs(list) do
		if list[i] and  list[i]~= "" then
			local data = Split(list[i],"|")
			local id = tonumber(data[1])
			local name = data[2]
			if id ~= guild_id then
				if newInvites == "" then
					newInvites = newInvites .. id.."|"..name
				else
					newInvites = newInvites .. ";" .. id.."|"..name
				end
			end
		end
	end

	player:setStringProp(ENTITY_STRPROP_GUILD_INVITE_DATA, newInvites)
	player:saveStringProp(ENTITY_STRPROP_GUILD_INVITE_DATA)
	player:syncStringProp(ENTITY_STRPROP_GUILD_INVITE_DATA)

end



--膜拜行会成员
function Guild.worshipMember(entity, guild, target_player_id, worship_type)
	--local target_member = guild:getMemberByPlayerID(target_player_id)
	
	local now_time = os.time()
	local now_day = math.floor(now_time / 24 / 60 / 60)

	local worship_day = entity:getProp(ENTITY_PROP_GUILD_WORSHIP_DAY)
	if worship_day ~= now_day then
		worship_day = now_day
		entity:setProp(ENTITY_PROP_GUILD_WORSHIP_DAY, now_day)
		entity:syncProp(ENTITY_PROP_GUILD_WORSHIP_DAY)
		entity:saveProp(ENTITY_PROP_GUILD_WORSHIP_DAY)
		entity:setProp(ENTITY_PROP_GUILD_WORSHIP_COUNT, 0)
		entity:syncProp(ENTITY_PROP_GUILD_WORSHIP_COUNT)
		entity:saveProp(ENTITY_PROP_GUILD_WORSHIP_COUNT)
		entity:setProp(ENTITY_PROP_GUILD_WORSHIP1, 0)
		entity:syncProp(ENTITY_PROP_GUILD_WORSHIP1)
		entity:saveProp(ENTITY_PROP_GUILD_WORSHIP1)
		entity:setProp(ENTITY_PROP_GUILD_WORSHIP2, 0)
		entity:syncProp(ENTITY_PROP_GUILD_WORSHIP2)
		entity:saveProp(ENTITY_PROP_GUILD_WORSHIP2)
		entity:setProp(ENTITY_PROP_GUILD_WORSHIP3, 0)
		entity:syncProp(ENTITY_PROP_GUILD_WORSHIP3)
		entity:saveProp(ENTITY_PROP_GUILD_WORSHIP3)
	end

	local worship_count = entity:getProp(ENTITY_PROP_GUILD_WORSHIP_COUNT)
	if worship_count >= 3 then
		--一天只能膜拜三次别的玩家
		return ERROR_GUILD_WORSHIP_COUNT_LIMIT
	end
	
	local worship1 = entity:getProp(ENTITY_PROP_GUILD_WORSHIP1)
	local worship2 = entity:getProp(ENTITY_PROP_GUILD_WORSHIP2)
	local worship3 = entity:getProp(ENTITY_PROP_GUILD_WORSHIP3)
	log.debug(worship1, worship2, worship3)
	if worship1 == target_player_id or worship2 == target_player_id or worship3 == target_player_id then
		--同一个玩家只能被膜拜一次
		return ERROR_GUILD_WORSHIP_EXIST
	end
	
	if worship_type == 0 then
		--免费膜拜
		entity:addExp(20000, OP_GUILD_WORSHIP_MEMBER)
	elseif worship_type == 1 then
		
	elseif worship_type == 2 then
		--10元宝膜拜
		if entity:getProp(ENTITY_PROP_LINGFU) < 10 then
			return ERROR_NOT_ENOUGH_INGOT
		end

		ret = entity:useIngot(10, OP_GUILD_WORSHIP_MEMBER)
		if ret == SUCCESS then
			entity:addExp(150000, OP_GUILD_WORSHIP_MEMBER)
		end
	else
		return ERROR_GUILD_WORSHIP_TYPE
	end
	
	--保存膜拜过的玩家
	entity:setProp(ENTITY_PROP_GUILD_WORSHIP1 + worship_count, target_player_id)
	entity:syncProp(ENTITY_PROP_GUILD_WORSHIP1 + worship_count)
	entity:saveProp(ENTITY_PROP_GUILD_WORSHIP1 + worship_count)

	--保存膜拜次数
	entity:setProp(ENTITY_PROP_GUILD_WORSHIP_COUNT, worship_count + 1)
	entity:syncProp(ENTITY_PROP_GUILD_WORSHIP_COUNT)
	entity:saveProp(ENTITY_PROP_GUILD_WORSHIP_COUNT)
	
	_G.addPlayerProp(target_player_id, ENTITY_PROP_GUILD_BE_WORSHIPED_COUNT, 1)
	_G.addPlayerProp(target_player_id, ENTITY_PROP_GUILD_BE_WORSHIPED_REWARD, 200)

	return SUCCESS
end

--领取被膜拜的奖励
function Guild.getBeWorshipedReward(entity, guild)
	local be_worshiped_count = entity:getProp(ENTITY_PROP_GUILD_BE_WORSHIPED_COUNT)
	local be_worshiped_reward = entity:getProp(ENTITY_PROP_GUILD_BE_WORSHIPED_REWARD)
	if be_worshiped_reward <= 0 then
		--没有未领取的奖励
		return ERROR_GUILD_NO_BE_WORSHIPED_REWARD
	end
	
	entity:setProp(ENTITY_PROP_GUILD_BE_WORSHIPED_COUNT, 0)
	entity:saveProp(ENTITY_PROP_GUILD_BE_WORSHIPED_COUNT)
	entity:syncProp(ENTITY_PROP_GUILD_BE_WORSHIPED_COUNT)
	entity:setProp(ENTITY_PROP_GUILD_BE_WORSHIPED_REWARD, 0)
	entity:saveProp(ENTITY_PROP_GUILD_BE_WORSHIPED_REWARD)
	entity:syncProp(ENTITY_PROP_GUILD_BE_WORSHIPED_REWARD)
end

--升级行会等级
function Guild.upgradeLevel(entity, guild, type)
	--仅会长和副会长可开启
	local post = entity:getProp(ENTITY_PROP_GUILD_POST)
	if post ~= GUILD_POST_MASTER and post ~= GUILD_POST_SECOND_MASTER then
		return ERROR_GUILD_AUTHORITY
	end
	
	--当前等级
	local cur_level = guild:getProp(GUILD_PROP_LEVEL)
	if cur_level < 1 then
		cur_level = 1
	end

	local cur_level_data = gdGuildLevelDatas[cur_level]
	if not cur_level_data then
		return ERROR_GUILD_DATA
	end

	if not cur_level_data.reqmoney or cur_level_data.reqmoney <= 0 then
		return ERROR_GUILD_NO_NEXT_LEVEL
	end

	--下一等级
	local next_level = cur_level + 1
	local next_level_data = gdGuildLevelDatas[next_level]
	if not next_level_data then
		return ERROR_GUILD_NO_NEXT_LEVEL
	end
	
	--检查行会资金
	local money = guild:getProp(GUILD_PROP_MONEY)
	if money < cur_level_data.reqmoney then
		--没有足够的行会资金
		return ERROR_GUILD_NOT_ENOUGH_GUILD_MONEY
	end
	
	--扣除行会资金
	guild:setProp(GUILD_PROP_MONEY, money - cur_level_data.reqmoney)
	guild:saveProp(GUILD_PROP_MONEY)
	guild:syncProp(GUILD_PROP_MONEY)
	
	--设置等级
	guild:setProp(GUILD_PROP_LEVEL, next_level)
	guild:saveProp(GUILD_PROP_LEVEL)
	guild:syncProp(GUILD_PROP_LEVEL)

	-- 处理加成属性
	local function handle(entity)
		if entity then
			--Guild.handleGuildAddAttr(entity)
		end
	end
	guild:forEach(handle)
	guild:addRecord(GUILD_RECORD_LEVEL_UP, next_level, 0, "", "")
	guild:recordMoneyOp(entity, money, -cur_level_data.reqmoney, OP_GUILD_UPGRADE)

	return SUCCESS
end

--清除行会升级CD请求
function Guild.clearUpgradeCD(entity, guild)
	--仅会长和副会长有权限
	local post = entity:getProp(ENTITY_PROP_GUILD_POST)
	if post ~= GUILD_POST_MASTER and post ~= GUILD_POST_SECOND_MASTER then
		return ERROR_GUILD_NOT_MASTER
	end

	if guild:getProp(GUILD_PROP_NEXT_LEVEL_TIME) <= os.time() then
		return ERROR_GUILD_UPGRADE_CD_ZERO
	end
	
	--行会等级
	local guild_level = guild:getProp(GUILD_PROP_LEVEL)

	--检查是否有足够的元宝
	local need_ingots = gdGuildLevelDatas[guild_level].clear_cdtime_ingot
	local ingots = entity:getProp(ENTITY_PROP_LINGFU) or 0
	if ingots < need_ingots then
		return ERROR_NOT_ENOUGH_INGOT
	end

	--扣除元宝
	local ret = entity:useIngot(need_ingots, OP_GUILD_CLEAR_UPGRADE_CD)
	if ret ~= SUCCESS then
		return ERROR_NOT_ENOUGH_INGOT
	end

	--设置下一级升级时间
	local next_level_time = os.time()
	guild:setProp(GUILD_PROP_NEXT_LEVEL_TIME, next_level_time);
	guild:saveProp(GUILD_PROP_NEXT_LEVEL_TIME)
	guild:syncProp(GUILD_PROP_NEXT_LEVEL_TIME)

	return SUCCESS
end

--开启行会副本
function Guild.openInstance(entity, guild, event_id)
	--仅会长和副会长可开启
	local post = entity:getProp(ENTITY_PROP_GUILD_POST)
	if post ~= GUILD_POST_MASTER and post ~= GUILD_POST_SECOND_MASTER then
		return ERROR_GUILD_NOT_MASTER
	end

	local lcsc =  entity:getScene()
	if lcsc then
		local scene_sid = lcsc:getStaticID()
		if scene_sid == MapID.hmjy or scene_sid == MapID.jjc then
			return ERROR_SCENE_NOT_ALLOW
		end
	end

	--检查行会副本是否已开放
	if not isSwitchEnabled(SWITCH_GUILD_SCENE, event_id) then
		return ERROR_FUNCTION_DISABLED
	end

	--检查活动是否开启
	local event_data = gdEventData[event_id]
	local es = Event.EventState[event_id]
	if not event_data or not es or not es.state then
		return ERROR_GUILD_EVENT_NOT_OPENED
	end
	
	--检查行会等级
	local guild_level = guild:getProp(GUILD_PROP_LEVEL)
	if not guild_level then
		guild_level = 1
	end
	if guild_level < event_data.require_guild_level then
		return ERROR_GUILD_NOT_ENOUGH_GUILD_LEVEL
	end
	
	--检查玩家等级
	local player_reborn = entity:getProp(ENTITY_PROP_REBORN)
	local player_level = entity:getLevel()
	local require_reborn = event_data.reborn or 0
	local require_level = event_data.requirelvl or 1
	if (player_reborn < require_reborn) or ((player_reborn == require_reborn) and (player_level < require_level)) then
		return ERROR_NOT_ENOUGH_LEVEL
	end

	--检查行会资金
	-- local money = guild:getProp(GUILD_PROP_MONEY)
	-- if not money or money < event_data.require_guild_money then
	-- 	--没有足够的行会资金
	-- 	return ERROR_GUILD_NOT_ENOUGH_GUILD_MONEY
	-- end
	
	--检查行会活跃度
	local vitality = guild:getProp(GUILD_PROP_VITALITY)
	if not vitality or vitality < event_data.require_guild_vitality then
		--没有足够的行会活跃度
		return ERROR_GUILD_NOT_ENOUGH_GUILD_VITALITY
	end

	--当前日期
	local now_date = os.date("*t", os.time())

	--同一时间只能开启一个行会副本
    local instance_time = guild:getProp(GUILD_PROP_OPEN_INSTANCE_TIME) or 0
	local instance_date = os.date("*t", instance_time)
    if now_date.yday == instance_date.yday then
        local instance_event_id = guild:getProp(GUILD_PROP_OPEN_INSTANCE_EVENT_ID) or 0
		if instance_event_id > 0 then
			return ERROR_GUILD_INSTANCE_ANOTHER_OPENED
        end
    end

	--检查今天是否已经开启过
	if guild:getProp(GUILD_PROP_INSTANCE_DAY) == now_date.yday then
		for i = GUILD_PROP_INSTANCE_BEGIN, GUILD_PROP_INSTANCE_END do
			if guild:getProp(i) == event_id then
				return ERROR_GUILD_INSTANCE_OPENED_TODAY
			end
		end
	end
	
	--扣除行会资金
	-- guild:setProp(GUILD_PROP_MONEY, money - event_data.require_guild_money)
	-- guild:saveProp(GUILD_PROP_MONEY)
	-- guild:syncProp(GUILD_PROP_MONEY)
	-- guild:recordMoneyOp(entity, 2007, event_data.require_guild_money, OP_LOST_THING)

	--扣除行会活跃度
	guild:setProp(GUILD_PROP_VITALITY, vitality - event_data.require_guild_vitality)
	guild:saveProp(GUILD_PROP_VITALITY)
	guild:syncProp(GUILD_PROP_VITALITY)
	--guild:recordMoneyOp(entity, 2007, event_data.require_guild_vitality, OP_LOST_THING)

	--已开启过的行会副本
	if guild:getProp(GUILD_PROP_INSTANCE_DAY) ~= now_date.yday then
		guild:setProp(GUILD_PROP_INSTANCE_DAY, now_date.yday)
		guild:saveProp(GUILD_PROP_INSTANCE_DAY)
		for i = GUILD_PROP_INSTANCE_BEGIN, GUILD_PROP_INSTANCE_END do
			guild:setProp(i, 0)
			guild:saveProp(i)
			--guild:syncProp(i)
		end
	end
	for i = GUILD_PROP_INSTANCE_BEGIN, GUILD_PROP_INSTANCE_END do
		if guild:getProp(i) == 0 then
			guild:setProp(i, event_id)
			guild:saveProp(i)
			--guild:syncProp(i)
			break
		end
	end

	guild:setProp(GUILD_PROP_OPEN_INSTANCE_PLAYER_ID, entity:getGlobalID())
	guild:saveProp(GUILD_PROP_OPEN_INSTANCE_PLAYER_ID)
	guild:syncProp(GUILD_PROP_OPEN_INSTANCE_PLAYER_ID)

	guild:setProp(GUILD_PROP_OPEN_INSTANCE_TIME, os.time())
	guild:saveProp(GUILD_PROP_OPEN_INSTANCE_TIME)
	guild:syncProp(GUILD_PROP_OPEN_INSTANCE_TIME)

	guild:setProp(GUILD_PROP_OPEN_INSTANCE_EVENT_ID, event_id)
	guild:saveProp(GUILD_PROP_OPEN_INSTANCE_EVENT_ID)
	guild:syncProp(GUILD_PROP_OPEN_INSTANCE_EVENT_ID)
	


	local ret = Scene.conveyEntityToNewInstance(entity, event_id)
	if ret ~= SUCCESS then
		return ret
	end

	scene = entity:getScene()
	if scene then
		--设置副本所属行会
		scene:setProp(SCENE_PROP_OWNER_GUILD_ID, guild:getID())

		--设置行会开启副本ID
		guild:setProp(GUILD_PROP_OPEN_INSTANCE_ID, scene:getID())

		--scene:forEachEntityM(function(monster)
		--	if monster:isMonster() and monster:isAlive() then
		--		monster:setProp(ENTITY_PROP_OWNER_TYPE, OWNER_TYPE_GUILD)
		--		monster:setProp(ENTITY_PROP_OWNER_DATA, scene:getProp(SCENE_PROP_OWNER_GUILD_ID))
		--		monster:setProp(ENTITY_PROP_MONSTER_TIME_TO_OWN, -1)
		--	end
		--end)
	end

	--新副本实例ID
	--entity:getProp(ENTITY_PROP_INSTANCE_IID)

	return ret
end

--进入行会副本
function Guild.enterInstance(entity, guild, event_id)
	
end

-- 是否在行会副本中
function Guild.isInGuildInstance(entity)
	local scene = entity:getScene()
	if not scene then return false end

	return scene:getStaticID() == MapID.ghboss10 or scene:getStaticID() == MapID.ghboss9 or
	scene:getStaticID() == MapID.ghboss8 or scene:getStaticID() == MapID.ghboss7 or
	scene:getStaticID() == MapID.ghboss6 or scene:getStaticID() == MapID.ghboss5 or
	scene:getStaticID() == MapID.ghboss4 or scene:getStaticID() == MapID.ghboss3 or
	scene:getStaticID() == MapID.ghboss2 or scene:getStaticID() == MapID.ghboss1
end


--会长删号把所有公会成员踢出公会采集
function Guild.kickoutFromGather(guild)
	if not Event.isActive(EVENT_GHCJ) then
		return
	end

	local scene = _G.getSceneByStaticID(MapID.ghcj)
	if not scene then return end

	scene:forEachPlayer(function (player)
		if player:getProp(ENTITY_PROP_GUILD_ID) == 0 then
			Scene.conveyBack(player)
		end
	end)
end


function Guild.NoticeAllPlayer(guild)
	local guild_id = guild:getID()

	_G.forEachPlayer(function (player)
		local newInvites = ""
		local strInvates = player:getStringProp(ENTITY_STRPROP_GUILD_INVITE_DATA)
		local list = Split(strInvates, ";")
		for i,v in ipairs(list) do
			if list[i] and  list[i]~= "" then
				local data = Split(list[i],"|")
				local id = tonumber(data[1])
				local name = data[2]
				if id ~= guild_id then
					if newInvites == "" then
						newInvites = newInvites .. id.."|"..name
					else
						newInvites = newInvites .. ";" .. id.."|"..name
					end
				end
			end
		end

		player:setStringProp(ENTITY_STRPROP_GUILD_INVITE_DATA, newInvites)
		player:saveStringProp(ENTITY_STRPROP_GUILD_INVITE_DATA)
		player:syncStringProp(ENTITY_STRPROP_GUILD_INVITE_DATA)
	end)
end

-- 行会删除
function Guild.onRelease(guild)
	Guild.NoticeAllPlayer(guild)
	Guild.rmvGuildBuff(guild)
	GCZ.onGuildRelease(guild)
end

-- 移除行会buff
function Guild.rmvGuildBuff(guild)
	local guild_level = guild:getProp(GUILD_PROP_LEVEL)
	local guildInfo = gdGuildLevelDatas[guild_level]
	guild:forEach(
		function(entity)
			-- 行会等级buff
			if guildInfo then
				if entity:hasGene(guildInfo.geneId) then
					entity:rmvGene(guildInfo.geneId)
				end
			end
		end
	)
end

--有人捐献装备
function Guild.sendPutItemMsg(guild, name, item_id, contribution, guild_id,iid)
	log.info("Guild.sendPutItemMsg:guildid" .. guild_id .. "," .. "item_id:" .. item_id .. ",iid:" .. iid)
	guild:syncFloatMessage("nofloat:" ..language.GetText(gdSvrLanguage[12].text, {name, item_id,-guild_id,iid,contribution}))
end

--会长无私捐献
function Guild.sendSelflessGiveItemMsg(guild, name, item_id, guild_id, iid)
	log.info("Guild.sendSelflessGiveItemMsg:guildid" .. guild_id .. "," .. "item_id:" .. item_id .. ",iid:" .. iid)
	guild:syncFloatMessage("nofloat:" .. language.GetText(gdSvrLanguage[149].text, {name, item_id, -guild_id, iid}))
end

--有人拿装备
function Guild.sendGetItemMsg(guild, name, item_id, contribution, pid,iid)
	log.info("Guild.sendGetItemMsg:guildid" .. guild:getID() .. "," .. "item_id:" .. item_id .. ",iid" .. iid .. ",pid" .. pid)

	if not gdItems[item_id] then
		return
	end

	if tonumber(gdItems[item_id].req_level) == nil then
		return
	end


	if (tonumber(gdItems[item_id].req_level) or 0) < 80 and (tonumber(gdItems[item_id].rebornlvl) or 0) < 1 then
		return
	end
	log.info("nofloat:" ..language.GetText(gdSvrLanguage[13].text, {name, contribution,item_id,pid,iid}))
	guild:syncFloatMessage("nofloat:" ..language.GetText(gdSvrLanguage[13].text, {name, contribution,item_id,pid,iid}))
end

---有人提升职位
function Guild.sendLevelUpPosMsg(guild, src, dst, pos)
	local str_pos = ""
	str_pos = Guild.GetDefaultNickname(pos)
	--guild:syncFloatMessage("nofloat:" .. src .. "将" .. dst .. "的职位提升为" .. str_pos)
	guild:syncFloatMessage(language.GetText(gdSvrLanguage[14].text, {src, dst, str_pos}))
end

---有人降低职位
function Guild.sendLevelDownPosMsg(guild, src, dst, pos)
	local str_pos = ""
	str_pos = Guild.GetDefaultNickname(pos)
	--guild:syncFloatMessage("nofloat:" .. src .. "将" .. dst .. "的职位改变为" .. str_pos)
	guild:syncFloatMessage(language.GetText(gdSvrLanguage[17].text, {src, dst, str_pos}))
end

---移交会长
function Guild.resetMasterMsg(guild, src, dst)
	--guild:syncFloatMessage("nofloat:" .. src .. "将" .. dst .. "的职位改变为" .. str_pos)
	guild:syncFloatMessage(language.GetText(gdSvrLanguage[102].text, {src, dst}))
end

-- 发送红包
function Guild.sendRedMsg(guild, src, gold, redtype)
	--_G.syncFloatMessage(guild:getGuildName() .. "的" .. src .. "发了" .. gold .. "元宝的红包")
	if redtype == GUILD_RED_PACKAGE_ACTIVITY then
		_G.syncFloatMessage(language.GetText(gdSvrLanguage[775].text, {guild:getGuildName(), src, gold}))
	else
		_G.syncFloatMessage(language.GetText(gdSvrLanguage[19].text, {guild:getGuildName(), src, gold}))
	end
end

-- 进入公会经验副本
function Guild.enterExpScene(entity, instanceID)
	
end

function Guild.getGuildChatText(teamid)
	return gdSvrLanguage[165].text
end

-- 获取帮会清理间隔
function Guild.onGetCleanGuildBagTime(guild)
	if gdGame.server_days > 2 then
		return Guild.timeinterval
	else
		-- 开服前两天5min清理一次
		return 300000
	end
end

-- 发送即将清理公告
function Guild.syncCleanNotice(guild)
	if gdGame.server_days > 2 then
		guild:syncFloatMessage("nofloat:" .. gdSvrLanguage[203].text)
	else
		guild:syncFloatMessage("nofloat:" .. gdSvrLanguage[313].text)
	end
end

-- 清理公会仓库
function Guild.onCleanGuildBag(guild)
	local items = {}
	for pos = GUILD_BAG_POS_FIRST, GUILD_BAG_POS_LAST do
		local item = guild:getItemByPos(pos)

		if item and gdItems[item:getStaticID()] and 
		(gdItems[item:getStaticID()].type ~= nil and 
		gdItems[item:getStaticID()].type > 0)  and 
		gdItems[item:getStaticID()].cate == ITEM_CATEGORY_EQUIP and 
		(gdItems[item:getStaticID()].rebornlvl == nil or gdItems[item:getStaticID()].rebornlvl < 1) then	
			
			table.insert(items, item)
		end
	end

	table.sort(items, function(a, b)
		local a_reqLevel = gdItems[a:getStaticID()].req_level
		local b_reqLevel = gdItems[b:getStaticID()].req_level

		if a_reqLevel > b_reqLevel then
			return false
		elseif a_reqLevel < b_reqLevel then 
			return true
		end

		return false
	end)

	local max_count = 12
	for k, item in ipairs(items) do
		if k > max_count then 
			break
		end

		guild:delItem(item:getID())
	end

	if gdGame.server_days > 2 then
		guild:syncFloatMessage("nofloat:" .. gdSvrLanguage[202].text)
	else
		guild:syncFloatMessage("nofloat:" .. gdSvrLanguage[312].text)
	end

	return SUCCESS
end

-- 公会一键合成60->70
function Guild.onGuildForge(entity)
	local guild = _G.getGuild(entity:getProp(ENTITY_PROP_GUILD_ID))
	if not guild then
		return ERROR_NOT_IN_GUILD
	end 

	local post = entity:getProp(ENTITY_PROP_GUILD_POST)
	if post ~= GUILD_POST_MASTER and post ~= GUILD_POST_SECOND_MASTER then
		return ERROR_GUILD_AUTHORITY
	end

	local formulaItem =	gdFormula[54]
	if formulaItem == nil then
		return ERROR_UNKNOWN
	end

	local stuffId          = formulaItem.stuffId
	local stuffCount       = formulaItem.stuffCount
	local stuffItem		   = gdItems[stuffId]

	if stuffItem == nil then
		return ERROR_UNKNOWN
	end

	if not stuffItem.type then 
		local costItems = {}
		
		for pos = GUILD_BAG_POS_FIRST, GUILD_BAG_POS_LAST do
			local item = guild:getItemByPos(pos)

			if item and gdItems[item:getStaticID()] and 
			(gdItems[item:getStaticID()].type ~= nil and 
			gdItems[item:getStaticID()].type > 0)  and 
			gdItems[item:getStaticID()].cate == ITEM_CATEGORY_EQUIP and 
			gdItems[item:getStaticID()].req_level >= stuffItem.req_level and 
			gdItems[item:getStaticID()].req_level < stuffItem.req_level + 10 and
			item:getProp(ITEM_PROP_ENHANCE_LEVEL) == 0 and 
			item:getProp(ITEM_PROP_SOUL_LEVEL) == 0 then	
				
				costItems[#costItems + 1]  = item:getID()
			end
		end
		if #costItems < stuffCount then
			return	ERROR_NOT_ENOUGH_ITEM
		end

		local mod = #costItems % stuffCount
		if mod ~= 0 then
			for i = 1, mod do
				table.remove(costItems, 1)
			end
		end

		--删除装备
		for index = 1, #costItems do
			guild:delItem(costItems[index])
		end

		local keys = {}
		for i = 28, 54 do
			if gdFormula[i].stuffCount == 5 then
				table.insert(keys, i)
			end
		end

		--增加装备
		for i = 1, (#costItems / stuffCount) do 
			local random = _G.MyRandom(#keys) + 1
			local id = keys[random]
			guild:addItem(gdFormula[id].stuffIid,1,OP_HC)
		end
	end

	return SUCCESS
end

-- @return 0可以采集 1不可以采集 2自己正在采集
function Guild.canGather(entity, eid)
	local scene = entity:getScene()
	if not scene then 
		return 1
	end

	local npc = scene:getEntity(eid)
	if not npc then
		return 1
	end

	if npc:getProp(ENTITY_PROP_NPC_DIE) == 1 then
		return 3
	end

	local ownID = npc:getProp(ENTITY_PROP_NPC_OWNER_PID)
	if ownID == entity:getGlobalID() then
		return 2
	end

	local owner = _G.getPlayerByPlayerID(ownID)
	if owner and owner:isAlive() and owner:getProp(ENTITY_PROP_OFFLINE) ~= 1 then
		return 1
	end

	return 0
end

--弹劾会长
function Guild.impeachMaster(player)
	local now = os.time()

	--发起人是否已经加入公会
	local guild_id = player:getProp(ENTITY_PROP_GUILD_ID)
	if not guild_id or guild_id <= 0 then
		player:sendShowNote(NOTE_TYPE_NORMAL, 1562)
		return ERROR_UNKNOWN
	end
	local guild = _G.getGuild(guild_id)
	if not guild then
		player:sendShowNote(NOTE_TYPE_NORMAL, 1562)
		return ERROR_UNKNOWN
	end

	--只有副会长和长老可以弹劾会长
	local guild_post = player:getProp(ENTITY_PROP_GUILD_POST)
	if guild_post ~= GUILD_POST_SECOND_MASTER and guild_post ~= GUILD_POST_ELDER then
		player:sendShowNote(NOTE_TYPE_NORMAL, 3298)
		return ERROR_UNKNOWN
	end

	--判断VIP等级
	local vip_level = player:getProp(ENTITY_PROP_VIP_LEVEL)
	if vip_level < 3 then
		player:sendShowNote(NOTE_TYPE_NORMAL, 3299)
		return ERROR_UNKNOWN;
	end
	
	--是否已经有人发起了弹劾
	if guild:getProp(GUILD_PROP_IMPEACH_PID) > 0 then
		if guild:getProp(GUILD_PROP_IMPEACH_PID) == player:getGlobalID() then
			player:sendShowNote(NOTE_TYPE_NORMAL, 3301)
		else
			player:sendShowNote(NOTE_TYPE_NORMAL, 3300)
		end
		return ERROR_UNKNOWN
	end

	--检查会长是否在线
	if guild:isMasterOnline() then
		player:sendShowNote(NOTE_TYPE_NORMAL, 3302)
		return ERROR_UNKNOWN
	end

	--检查会长离线时长
	local logout_time = 24 * 3600
	if gdGame.server_days > 3 then
		logout_time = 72 * 3600
	end
	local cur_logout_time = now - guild:getProp(GUILD_PROP_MASTER_LAST_LOGOUT_TIME)
	if cur_logout_time < logout_time then
		local hour = math.floor(cur_logout_time/3600)
		local min = math.floor(cur_logout_time/60) % 60
		player:sendShowNote(NOTE_TYPE_NORMAL, 3303, logout_time/3600, hour, min)
		return ERROR_UNKNOWN
	end
	
	--是否有足够的元宝
	local ret = player:useIngot(200, OP_IMPEACH)
	if ret ~= SUCCESS then
		return ret
	end

	player:setProp(ENTITY_PROP_IMPEACH_VOTED, now)
	player:saveProp(ENTITY_PROP_IMPEACH_VOTED)
	player:syncProp(ENTITY_PROP_IMPEACH_VOTED)

	guild:setProp(GUILD_PROP_IMPEACH_PID, player:getGlobalID())
	guild:setProp(GUILD_PROP_IMPEACH_TIME, now)
	guild:setProp(GUILD_PROP_IMPEACH_AGREE, 1)
	guild:setProp(GUILD_PROP_IMPEACH_DISAGREE, 0)
	
	guild:saveProp(GUILD_PROP_IMPEACH_PID)
	guild:saveProp(GUILD_PROP_IMPEACH_TIME)
	guild:saveProp(GUILD_PROP_IMPEACH_AGREE)
	guild:saveProp(GUILD_PROP_IMPEACH_DISAGREE)

	guild:syncProp(GUILD_PROP_IMPEACH_AGREE)
	guild:syncProp(GUILD_PROP_IMPEACH_DISAGREE)
	guild:syncProp(GUILD_PROP_IMPEACH_TIME)
	guild:syncProp(GUILD_PROP_IMPEACH_PID)

	player:syncChatMsg(CHAT_TYPE_GUILD, language.GetText(gdCliLanguage[3304].text, {player:getName()}))

	return SUCCESS
end

--弹劾会长投票
function Guild.impeachVote(player, time, vote)
	local guild_id = player:getProp(ENTITY_PROP_GUILD_ID)
	if not guild_id or guild_id <= 0 then
		player:sendShowNote(NOTE_TYPE_NORMAL, 1562)
		return ERROR_UNKNOWN
	end

	local guild = _G.getGuild(guild_id)
	if not guild then
		player:sendShowNote(NOTE_TYPE_NORMAL, 1562)
		return ERROR_UNKNOWN
	end

	--检查是否有人发起弹劾
	local impeach_pid = guild:getProp(GUILD_PROP_IMPEACH_PID)
	if impeach_pid == 0 then
		player:sendShowNote(NOTE_TYPE_NORMAL, 3296)
		return
	end
	
	--新成员没有投票权限
	local impeach_time = guild:getProp(GUILD_PROP_IMPEACH_TIME)
	if guild:getMemberIntime(player:getGlobalID()) > impeach_time then
		player:sendShowNote(NOTE_TYPE_NORMAL, 3291)
		return ERROR_UNKNOWN
	end

	-- 检查投票是否已经结束
	local now = os.time()
	if time ~= impeach_time or now < impeach_time or now - impeach_time >= 2 * 3600 then
		player:sendShowNote(NOTE_TYPE_NORMAL, 3296)
		return
	end

	-- 检查是否已经投过票了
	local voted = player:getProp(ENTITY_PROP_IMPEACH_VOTED)
	if voted == impeach_time then
		player:sendShowNote(NOTE_TYPE_NORMAL, 3305)
		return
	end

	player:setProp(ENTITY_PROP_IMPEACH_VOTED, impeach_time)
	player:saveProp(ENTITY_PROP_IMPEACH_VOTED)
	player:syncProp(ENTITY_PROP_IMPEACH_VOTED)

	if vote == 0 then
		guild:addProp(GUILD_PROP_IMPEACH_DISAGREE, 1)
		guild:saveProp(GUILD_PROP_IMPEACH_DISAGREE)
		guild:syncProp(GUILD_PROP_IMPEACH_DISAGREE)
	else
		guild:addProp(GUILD_PROP_IMPEACH_AGREE, 1)
		guild:saveProp(GUILD_PROP_IMPEACH_AGREE)
		guild:syncProp(GUILD_PROP_IMPEACH_AGREE)
	end
end

--弹劾是否结束
function Guild.impeachCheck(guild)
	local impeach_pid = guild:getProp(GUILD_PROP_IMPEACH_PID)
	if impeach_pid == 0 then
		return
	end

	-- 检查投票是否已经结束
	local now = os.time()
	local impeach_time = guild:getProp(GUILD_PROP_IMPEACH_TIME)
	if now >= impeach_time and now - impeach_time < 2 * 3600 then
		return
	end

	local impeach_agree = guild:getProp(GUILD_PROP_IMPEACH_AGREE)
	local impeach_disagree = guild:getProp(GUILD_PROP_IMPEACH_DISAGREE)

	if impeach_agree > impeach_disagree then
		--移交会长
		local old_master_name = guild:getMasterName()
		guild:changeMaster(impeach_pid)

		guild:setProp(GUILD_PROP_MASTER_LAST_LOGOUT_TIME, now)
		guild:saveProp(GUILD_PROP_MASTER_LAST_LOGOUT_TIME)
		guild:syncProp(GUILD_PROP_MASTER_LAST_LOGOUT_TIME)

		guild:forEachPlayerID(function(member_pid)
			_G.sendMail(member_pid, gdSvrLanguage[210].text, language.GetText(gdSvrLanguage[211].text, {old_master_name, guild:getMasterName()}))
		end)

		guild:addRecord(GUILD_RECORD_IMPEACH, 0, 0, guild:getMasterName(), "")
	else
		guild:forEachPlayerID(function(member_pid)
			_G.sendMail(member_pid, gdSvrLanguage[212].text, gdSvrLanguage[213].text)
		end)
		guild:addRecord(GUILD_RECORD_IMPEACH, -1, 0, "", "")
	end

	guild:setProp(GUILD_PROP_IMPEACH_PID, 0)
	guild:setProp(GUILD_PROP_IMPEACH_TIME, 0)
	guild:setProp(GUILD_PROP_IMPEACH_AGREE, 0)
	guild:setProp(GUILD_PROP_IMPEACH_DISAGREE, 0)
	
	guild:saveProp(GUILD_PROP_IMPEACH_PID)
	guild:saveProp(GUILD_PROP_IMPEACH_TIME)
	guild:saveProp(GUILD_PROP_IMPEACH_AGREE)
	guild:saveProp(GUILD_PROP_IMPEACH_DISAGREE)

	guild:syncProp(GUILD_PROP_IMPEACH_AGREE)
	guild:syncProp(GUILD_PROP_IMPEACH_DISAGREE)
	guild:syncProp(GUILD_PROP_IMPEACH_TIME)
	guild:syncProp(GUILD_PROP_IMPEACH_PID)
end

function Guild.impeachCancel(guild)
	if not guild then
		return
	end

	local impeach_pid = guild:getProp(GUILD_PROP_IMPEACH_PID)
	if impeach_pid == 0 then
		return
	end

	guild:addRecord(GUILD_RECORD_IMPEACH, -1, 0, "", "")

	--返还弹劾花费
	_G.sendMail(impeach_pid, gdSvrLanguage[208].text, gdSvrLanguage[209].text, {static_id=3, count=200})

	guild:setProp(GUILD_PROP_IMPEACH_PID, 0)
	guild:setProp(GUILD_PROP_IMPEACH_TIME, 0)
	guild:setProp(GUILD_PROP_IMPEACH_AGREE, 0)
	guild:setProp(GUILD_PROP_IMPEACH_DISAGREE, 0)
	
	guild:saveProp(GUILD_PROP_IMPEACH_PID)
	guild:saveProp(GUILD_PROP_IMPEACH_TIME)
	guild:saveProp(GUILD_PROP_IMPEACH_AGREE)
	guild:saveProp(GUILD_PROP_IMPEACH_DISAGREE)

	guild:syncProp(GUILD_PROP_IMPEACH_AGREE)
	guild:syncProp(GUILD_PROP_IMPEACH_DISAGREE)
	guild:syncProp(GUILD_PROP_IMPEACH_TIME)
	guild:syncProp(GUILD_PROP_IMPEACH_PID)
end

--全服公告：XXX公会的XXX捐献了XXX元宝
function Guild.sendIngotContributionMsg(guild, playerName, ingot)
	if ingot >= 10000 then
		log.info("Guild.sendIngotContributionMsg:guildid" .. guild:getID() .. "," .. "name:" .. playerName .. ",ingot:" .. ingot)
		_G.syncFloatMessage(language.GetText(gdSvrLanguage[314].text, { guild:getGuildName(), playerName, ingot}))
	end
end

--全服公告：XXX公会已由会长正式更名为XXX
function Guild.sendRenameMsg(oldName, newName)
	_G.syncFloatMessage(language.GetText(gdSvrLanguage[316].text, {oldName, newName}))
end

-- 公会商城购买
function Guild.buyItem( guild, entity, sid, cnt )

end


--公会捐献
function Guild.donate(player, type)
	local guild_id = player:getProp(ENTITY_PROP_GUILD_ID)
	if not guild_id or guild_id <= 0 then	
		return ERROR_GUILD_NO_GUILD
	end

	local guild = _G.getGuild(guild_id)
	if not guild then
		return ERROR_GUILD_NOT_EXIST
	end
 
	local doNate = gdGuildDenoteData[type]
	if not doNate then
		return ERROR_UNKNOWN
	end
	local post = player:getProp(ENTITY_PROP_GUILD_POST)--职位
	local dataX = player:getEventDataX(EVENT_GUILD_DONATE_REWARD) --次数
	local maxTime =  doNate.maxtime

	local val1 = math.floor(dataX/10000)
	if type == 1 then--物品捐献	
		if  val1 >= maxTime then--已经达到最大次数 
			return ERROR_OVER_MAX_LIMIT
		end
	else
		return ERROR_INVALID_PARAM
	end
	
	-- 消耗物品
	local ret = player:rmvItem(doNate.consumeid, doNate.consumenum, BAG_TYPE_PLAYER,OP_GUILD_NOENT)
	if ret ~= SUCCESS then
		return ret
	end
	
	player:addItem(doNate.giftid, 1, OP_GUILD_REWARD)
		
	val1 = val1 + 1
	local newVal =  val1 * 10000
	--次数
	player:setEventDataX(EVENT_GUILD_DONATE_REWARD, newVal)
	player:saveEventData(EVENT_GUILD_DONATE_REWARD)
	player:syncEventData(EVENT_GUILD_DONATE_REWARD)

	--增加行会资金
	local todayMaxTime = guild:getProp(GUILD_PROP_MONEY_COUNT)
	local guildlvl = guild:getProp(GUILD_PROP_LEVEL)
	
	local money = guild:getProp(GUILD_PROP_MONEY)
	local newMoney = money + doNate.donaterate

	guild:setProp(GUILD_PROP_MONEY, newMoney)
	guild:syncProp(GUILD_PROP_MONEY)
	guild:saveProp(GUILD_PROP_MONEY)

	if type == 1 then
		guild:addRecord(GUILD_RECORD_DEVOTEITEM, doNate.consumeid, doNate.donaterate, player:getName(), "")
	end	
	-- 自动升级
	Guild.AutoupgradeLevel(guild)
	return SUCCESS
end

--升级行会等级
function Guild.AutoupgradeLevel(guild, type)	
	--当前等级
	local cur_level = guild:getProp(GUILD_PROP_LEVEL)
	if cur_level < 1 then
		cur_level = 1
	end

	local cur_level_data = gdGuildLevelDatas[cur_level]
	if not cur_level_data then
		return ERROR_GUILD_DATA
	end

	if not cur_level_data.builddata then
		return ERROR_GUILD_NO_NEXT_LEVEL
	end

	--下一等级
	local next_level = cur_level + 1
	local next_level_data = gdGuildLevelDatas[next_level]
	if not next_level_data then
		return ERROR_GUILD_NO_NEXT_LEVEL
	end
	
	--检查行会资金
	local money = guild:getProp(GUILD_PROP_MONEY)
	if money < cur_level_data.builddata then
		--没有足够的行会资金
		return ERROR_GUILD_NOT_ENOUGH_GUILD_MONEY
	end
	
	--扣除行会资金
	guild:setProp(GUILD_PROP_MONEY, money - cur_level_data.builddata)
	guild:saveProp(GUILD_PROP_MONEY)
	guild:syncProp(GUILD_PROP_MONEY)
	
	--设置等级
	guild:setProp(GUILD_PROP_LEVEL, next_level)
	guild:saveProp(GUILD_PROP_LEVEL)
	guild:syncProp(GUILD_PROP_LEVEL)

	-- 更新buff加成
	local old_gene_id = cur_level_data.geneId
	local new_gene_id = next_level_data.geneId
	guild:forEach(function(entity)
		-- 去除
		if entity:hasGene(old_gene_id) then
			entity:rmvGene(old_gene_id)
		end
		-- 增加
		if not entity:hasGene(new_gene_id) then
			entity:addGene(new_gene_id)
		end
	end)

	return SUCCESS
end

--公会捐献奖励
function Guild.donateAward(player, index)

	local guild_id = player:getProp(ENTITY_PROP_GUILD_ID)
	if not guild_id or guild_id <= 0 then	
		return ERROR_GUILD_NO_GUILD
	end

	local guild = _G.getGuild(guild_id)
	if not guild then
		return ERROR_GUILD_NOT_EXIST
	end

	
	local giftConfig = gdActivityGift[49].rewards
	if not giftConfig then
		return ERROR_UNKNOWN
	end

	if player:getBagEmptyCnt() == 0 then
		return ERROR_BAG_NOT_ENOUGH --背包格子不够
	end
	local todaymoney = guild:getProp(GUILD_PROP_MONEY_TODAY_MONEY)
	--当日贡献度是否达到 
	local reachValue = giftConfig[index].datax
	if todaymoney < reachValue then
		return ERROR_UNKNOWN
	end

	--是否已经领取过
	local dataY = player:getEventDataY(EVENT_GUILD_DONATE_REWARD) --次数
	local mark = bit.lshift(1, index)
	local get = bit.band(dataY, mark)
	if 0 ~= get then
		return ERROR_UNKNOWN
	end

	dataY = bit.bor(dataY, mark)	
	player:setEventDataY(EVENT_GUILD_DONATE_REWARD, dataY)
	player:saveEventData(EVENT_GUILD_DONATE_REWARD)
	player:syncEventData(EVENT_GUILD_DONATE_REWARD)

	player:addItem(giftConfig[index].iid, 1, OP_GUILD_REWARD)

end


function Guild.donateCheck(guild)
	local time = os.date("*t")
	local todayTime = time.year..time.month..time.day
	local today = guild:getProp(GUILD_PROP_MONEY_TODAY_TIME)

	if today == 0 then
		guild:setProp(GUILD_PROP_MONEY_TODAY_TIME,tonumber(todayTime))
		guild:saveProp(GUILD_PROP_MONEY_TODAY_TIME)
		return
	end
	
	if today ~= tonumber(todayTime) then
		guild:setProp(GUILD_PROP_MONEY_TODAY_TIME,tonumber(todayTime))
		guild:saveProp(GUILD_PROP_MONEY_TODAY_TIME)

		guild:setProp(GUILD_PROP_MONEY_COUNT,0)
		guild:syncProp(GUILD_PROP_MONEY_COUNT)
		guild:saveProp(GUILD_PROP_MONEY_COUNT)
	
		guild:setProp(GUILD_PROP_MONEY_TODAY_MONEY,0)
		guild:syncProp(GUILD_PROP_MONEY_TODAY_MONEY)
		guild:saveProp(GUILD_PROP_MONEY_TODAY_MONEY)
	end
		
end
--公会各个职务人数

function Guild.getPostNum(guildLevel,post)
	local num = 1
	if post == GUILD_POST_MASTER  then --会长 
		num = 1
	elseif	post == GUILD_POST_SECOND_MASTER then--副会长
		num = 2
	elseif post == GUILD_POST_ELITE then --精英
		if gdGuildLevelDatas[guildLevel] then
			num = gdGuildLevelDatas[guildLevel].eliteNum
		end
	elseif post == GUILD_POST_PROTECTOR then --护法
		if gdGuildLevelDatas[guildLevel] then
			num = gdGuildLevelDatas[guildLevel].protectorNum
		end
	-- elseif post == GUILD_POST_ELDER then --长老
		-- num = 2
	elseif  post == GUILD_POST_NORMAL then --帮众
		if gdGuildLevelDatas[guildLevel] then
			num = gdGuildLevelDatas[guildLevel].normalNum
		end
	end
	return num
end

-- 获取工会等级资金上限
function Guild.getMoneyMax(guildLevel)
	return gdGuildLevelDatas[guildLevel].MoneyMax
end

--当前技能等级
function Guild.getSkillLevel(player,index)
	local strskill = player:getStringProp(ENTITY_STRPROP_GUILD_SKILL_DATA)
	local list = Split(strskill, ";")
	for i,v in ipairs(list) do
		if list[i] and  list[i]~= "" then
			local data = Split(list[i],"|")
			local id = tonumber(data[1])
			local level = tonumber(data[2])
			if id == index then
				 return level
			end
		end
	end
	return 0
end

--通过技能等级来获取最低的公会等级
function Guild.getMinLevelBySkillLevel(index, sLevel)
	local skillGuild = gdGuildSkill[index]
	if skillGuild and skillGuild.skills then
		for i,v in ipairs(skillGuild.skills) do
			if v.level == sLevel then
				return v.glevel
			end
		end
	end
	
	return 1
end

--公会技能
function Guild.studySkill(player,index)
	local guild_id = player:getProp(ENTITY_PROP_GUILD_ID)
	if not guild_id or guild_id <= 0 then
		return ERROR_GUILD_NO_GUILD
	end

	local guild = _G.getGuild(guild_id)
	if not guild then
		player:sendShowNote(NOTE_TYPE_NORMAL, 1562)
		return ERROR_GUILD_NOT_EXIST
	end

	local level = guild:getProp(GUILD_PROP_LEVEL)
	--消耗贡献
	local upLevel = Guild.getSkillLevel(player,index)
	local config = gdGuildSkill[index]
	local useSkillConfig = config.skills[upLevel + 1]
	if not useSkillConfig then --等级已满
		return ERROR_UNKNOWN
	end
	--升级要看公会等级是否达到
	if useSkillConfig.glevel > level then
		return ERROR_UNKNOWN
	end

	local consume = useSkillConfig.consume
	local contribution = player:getProp(ENTITY_PROP_GUILD_CONTRIBUTION)
	if contribution < consume then
		return ERROR_GUILD_SHOP_NOT_ENOUGH_CONTRIBUTION
	end

	local errcode = player:addGuildContribution(-consume,OP_GUILD_STUDY_SKILL)
	if errcode ~= SUCCESS then
		return ERROR_GUILD_SHOP_NOT_ENOUGH_CONTRIBUTION
	end

	local ishave = false
	local skillS = ""
	local strskill = player:getStringProp(ENTITY_STRPROP_GUILD_SKILL_DATA)
	local list = Split(strskill, ";")
	for i,v in ipairs(list) do
		if list[i] and  list[i]~= "" then
			local data = Split(list[i],"|")
			local id = tonumber(data[1])  --技能id
			local level = tonumber(data[2])  --技能等级
			if id == index then
				ishave = true
				level = level + 1
				if skillS == "" then
					skillS = skillS .. id .."|"..level
				else
					skillS = skillS ..";"..id.."|"..level
				end
			else
				if skillS == "" then
					skillS = skillS ..id .."|"..level
				else
					skillS = skillS ..";" ..id .."|"..level
				end
			end
		end
	end
	if not ishave  then
		if skillS =="" then
			skillS = skillS ..index .."|"..1
		else
			skillS = skillS ..";" ..index .."|"..1
		end
	end
	player:setStringProp(ENTITY_STRPROP_GUILD_SKILL_DATA, skillS)
	player:saveStringProp(ENTITY_STRPROP_GUILD_SKILL_DATA)
	player:syncStringProp(ENTITY_STRPROP_GUILD_SKILL_DATA)
 
	-- 属性
	local cbt = player:getCombat()
	if not ishave then
		Combat.addAttr(cbt, useSkillConfig.props[1], player)
	else
		local beforeSkillConfig = config.skills[upLevel]
		Combat.rmvAttr(cbt, beforeSkillConfig.props[1], player)
		Combat.addAttr(cbt, useSkillConfig.props[1], player)
	end
	player:syncPlayerCombatCombo()
	return SUCCESS
end

--重置公会技能
function Guild.resetSkill(player)
	local guild_id = player:getProp(ENTITY_PROP_GUILD_ID)
	if not guild_id or guild_id <= 0 then
		return ERROR_GUILD_NO_GUILD
	end

	local guild = _G.getGuild(guild_id)
	if not guild then
		player:sendShowNote(NOTE_TYPE_NORMAL, 1562)
		return ERROR_GUILD_NOT_EXIST
	end

	local strskill = player:getStringProp(ENTITY_STRPROP_GUILD_SKILL_DATA)
	if #strskill == 0 then
		return ERROR_UNKNOWN
	end

	-- 属性
	local cbt = player:getCombat()
	local contribution = 0

	local list = Split(strskill, ";")
	for _, v in ipairs(list) do
		if v and v ~= "" then
			local data = Split(v, "|")
			local id = tonumber(data[1])  --技能id
			local level = tonumber(data[2])  --技能等级

			local config = gdGuildSkill[id]
			local cur_skill = config.skills[level]
			Combat.rmvAttr(cbt, cur_skill.props[1], player)

			for i = 1, level do
				local skill_cfg = config.skills[i]
				if skill_cfg and skill_cfg.consume then
					contribution = contribution + skill_cfg.consume
				end
			end
		end
	end
	player:addGuildContribution(contribution, OP_GUILD_RESET_SKILL)
	player:syncPlayerCombatCombo()

	player:setStringProp(ENTITY_STRPROP_GUILD_SKILL_DATA, "")
	player:saveStringProp(ENTITY_STRPROP_GUILD_SKILL_DATA)
	player:syncStringProp(ENTITY_STRPROP_GUILD_SKILL_DATA)

	return SUCCESS
end

--上线登录添加公会技能属性
function Guild.onCheckGuildSkillAttr(player)
	local cbt = player:getCombat()
	local strskill =  player:getStringProp(ENTITY_STRPROP_GUILD_SKILL_DATA)
	local list = Split(strskill, ";")
	for i,v in ipairs(list) do
		if list[i] and  list[i]~= "" then
			local data = Split(list[i],"|")
			local index = tonumber(data[1])
			local level = tonumber(data[2])
			local config = gdGuildSkill[index]
			if config and  level > 0 then
				Combat.addAttr(cbt, config.skills[level].props[1], player)
			end
		end
	end
end
--------------------------------------公会科技----------------------------------
local funTechLevel = {
	[1] = GUILD_PROP_YNQL_LEVEL,
	 --一念千里
	[2] = GUILD_PROP_QZYB_LEVEL,
	 --奇珍异宝
	[3] = GUILD_PROP_RJDJ_LEVEL,
	 --日进斗金
	[4] = GUILD_PROP_FKDG_LEVEL,
	 --富可敌国
	[5] = GUILD_PROP_CBTX_LEVEL,
	 --吃遍天下
	[6] = GUILD_PROP_JSCD_LEVEL
 --积少成多
}
--功能科技
local function funTechUpLevel(player,guild,techIndex)
	local propIndex = funTechLevel[techIndex]
	if not propIndex then
		return ERROR_UNKNOWN
	end

	local money = guild:getProp(GUILD_PROP_MONEY)
	local tecLevel = guild:getProp(propIndex)
	local funConfig = gdGuildfunTech[techIndex]
	if funConfig == nil then
		return ERROR_UNKNOWN
	end

	if funConfig.funs == nil then
		return ERROR_UNKNOWN
	end

	if funConfig.funs[tecLevel+1] == nil then
		return ERROR_UNKNOWN
	end

	local needConsume = funConfig.funs[tecLevel+1].consume
	if not needConsume then
		return ERROR_UNKNOWN
	end
	if money < needConsume then
		return ERROR_GUILD_NOT_ENOUGH_MONEY
	end

	--扣除行会资金
	guild:setProp(GUILD_PROP_MONEY,money - needConsume)
	guild:saveProp(GUILD_PROP_MONEY)
	guild:syncProp(GUILD_PROP_MONEY)
	--升级
	guild:setProp(propIndex,tecLevel + 1)
	guild:saveProp(propIndex)
	guild:syncProp(propIndex)
	if tecLevel + 1 == 1 then
		player:sendShowNote(NOTE_TYPE_NORMAL, 30478)
	else
		player:sendShowNote(NOTE_TYPE_NORMAL, 30479)
	end
	--行会记录
	guild:addRecord(GUILD_RECORD_TECHNOLOGY_FUN, techIndex, tecLevel + 1, player:getName(), "")

	return SUCCESS
end

local proTechLevel = {
	[1] = GUILD_PROP_FCDC_LEVEL,
	 --风驰电掣
	[2] = GUILD_PROP_SNLB_LEVEL,
	 --势若奔雷
	[3] = GUILD_PROP_JRBB_LEVEL,
	 --坚忍不拔
	[4] = GUILD_PROP_GRJT_LEVEL,
	 --固若金汤
	[5] = GUILD_PROP_LTWJ_LEVEL,
	 --雷霆万钧
	[6] = GUILD_PROP_KBYZ_LEVEL
 --狂暴意志
}
--属性科技
local function proTechUpLevel(player,guild,techIndex)
	local propIndex = proTechLevel[techIndex]
	if not propIndex then
		return ERROR_UNKNOWN
	end

	local money = guild:getProp(GUILD_PROP_MONEY)
	local tecLevel = guild:getProp(propIndex)
	local proConfig = gdGuildProTech[techIndex]
	local needConsume = proConfig.consume
	if not needConsume then
		return ERROR_UNKNOWN
	end
	if money < needConsume then
		return ERROR_GUILD_NOT_ENOUGH_MONEY
	end

	local levelConfig = proConfig.funs
	if tecLevel >= #levelConfig then
		return ERROR_UNKNOWN
	end

	--扣除行会资金
	guild:setProp(GUILD_PROP_MONEY,money - needConsume)
	guild:saveProp(GUILD_PROP_MONEY)
	guild:syncProp(GUILD_PROP_MONEY)
    local skillLevel = 0
	if tecLevel == 0 then--激活
		guild:setProp(propIndex,1)
		guild:saveProp(propIndex)
		guild:syncProp(propIndex)
		skillLevel = 1
		player:sendShowNote(NOTE_TYPE_NORMAL, 30478)	
	else
		
		local totalRate = 0
		for idx=1, #levelConfig do
			totalRate = totalRate + levelConfig[idx].weight
		end
		
		local weight = 0
		local rate = math.random(totalRate)
		for i = 1, #levelConfig do
			weight = weight + levelConfig[i].weight
			if weight >= rate then
				skillLevel = i
				break
			end
		end
		--升级
		guild:setProp(propIndex,skillLevel)
		guild:saveProp(propIndex)
		guild:syncProp(propIndex)
		player:sendShowNote(NOTE_TYPE_NORMAL, 30480)
	end
	--行会记录
	if skillLevel >= 5 or (tecLevel == 0 and skillLevel == 1) then		
		guild:addRecord(GUILD_RECORD_TECHNOLOGY_PRO, techIndex, skillLevel, player:getName(), "")
	end
	
	return SUCCESS
end

-----科技升级
function Guild.onUpGuildTechLevel(player,techType,techIndex)
	local guild_id = player:getProp(ENTITY_PROP_GUILD_ID)
	if not guild_id or guild_id <= 0 then
		return ERROR_GUILD_NO_GUILD
	end

	local guild = _G.getGuild(guild_id)
	if not guild then
		player:sendShowNote(NOTE_TYPE_NORMAL, 1562)
		return ERROR_GUILD_NOT_EXIST
	end

	local post = player:getProp(ENTITY_PROP_GUILD_POST)--职位
	if post ~= GUILD_POST_MASTER and post ~= GUILD_POST_SECOND_MASTER then
		return ERROR_GUILD_NOT_MASTER
	end
	local errcode = ERROR_UNKNOWN
	if techType == 1 then
		errcode = funTechUpLevel(player,guild,techIndex)
	elseif techType == 2 then
		errcode = proTechUpLevel(player,guild,techIndex)
	end

	return errcode
end
--属性科技重置
function Guild.onResetProTechnologyLevel(guild)

	--后续添加玩家属性清除
	guild:forEach(
		function(entity)
			if entity then
				for k,index in ipairs(proTechLevel) do
					if index == GUILD_PROP_JRBB_LEVEL or index == GUILD_PROP_GRJT_LEVEL
					 or index == GUILD_PROP_LTWJ_LEVEL or index == GUILD_PROP_KBYZ_LEVEL 
					 or index == GUILD_PROP_FCDC_LEVEL or index == GUILD_PROP_SNLB_LEVEL then
						local proConfig = gdGuildProTech[k]
						local levelConfig = proConfig.funs
						local tecLevel = guild:getProp(index)
						if tecLevel > 0 then
							Guild.removeProTechnologyValue(entity,index,levelConfig[tecLevel].data)
						end
					end
				end
				entity:syncPlayerCombatCombo()
			end
		end
	)

	for k,v in ipairs(proTechLevel)do
		guild:setProp(proTechLevel[k],0)
		guild:saveProp(proTechLevel[k])
		guild:syncProp(proTechLevel[k])
	end
end

--移除属性科技加成属性
function Guild.removeProTechnologyValue(player,index,addData)
	local cbt = player:getCombatSys()
	if index == GUILD_PROP_JRBB_LEVEL then--生命加成  坚忍不拔
		cbt:addProp(COMBAT_PROP_HP_MAX + COMBAT_PROP_NORMAL_END, -addData * 10)
	elseif index == GUILD_PROP_GRJT_LEVEL then --防御加成 固若金汤
		cbt:addProp(COMBAT_PROP_PDEF_PRO, -addData * 10)
	elseif index == GUILD_PROP_LTWJ_LEVEL then--攻击加成 雷霆万钧
		cbt:addProp(COMBAT_PROP_PATK_PRO, -addData * 10)
	elseif index == GUILD_PROP_KBYZ_LEVEL then--会心伤害加成 狂暴意志

	elseif index == GUILD_PROP_FCDC_LEVEL then-- pk伤害加成
		cbt:addProp(COMBAT_PROP_ADDATK_TO_PLAYER, -addData * 10)
	elseif index == GUILD_PROP_SNLB_LEVEL then--攻击速度加成 势若奔雷
		-- cbt:addProp(COMBAT_PROP_EXERCISE_MAX + COMBAT_PROP_NORMAL_END, -addData * 10)
	end
end

--上线公会科技属性加成
function Guild.onCheckGuildProTechnologyAttr(player)
	local guild_id = player:getProp(ENTITY_PROP_GUILD_ID)
	if not guild_id or guild_id <= 0 then
		return
	end
	local guild = _G.getGuild(guild_id)
	if not guild then
		return
	end
end

--离开公会科技属性加成去除
function Guild.leaveGuildProTechnologyAttrRemove(player)
	local guild_id = player:getProp(ENTITY_PROP_GUILD_ID)
	if not guild_id or guild_id <= 0 then
		return
	end
	local guild = _G.getGuild(guild_id)
	if not guild then
		return
	end

end

--获取公会功能科技等级
function Guild.getFunTechnologyData(player,index)
	local guild_id = player:getProp(ENTITY_PROP_GUILD_ID)
	if not guild_id or guild_id <= 0 then
		return 0
	end
	local guild = _G.getGuild(guild_id)
	if not guild then
		return 0
	end
	local key = 0
	for k, v in ipairs(funTechLevel)do
		if index == v then
			key = k
			break
		end
	end
	local proConfig = gdGuildfunTech[key]
	if not proConfig then
		return 0
	end 
	
	if index >= GUILD_PROP_YNQL_LEVEL and index<=GUILD_PROP_JSCD_LEVEL then
		local techLevel =  guild:getProp(index)
		if techLevel > 0 then
		   return proConfig.funs[techLevel].data
		end
	end
	return 0
end

--公会红包 是否满足条件
function Guild.SendRedToCheck(player, redtype, max_gold)
	local guild_id = player:getProp(ENTITY_PROP_GUILD_ID)
	if not guild_id or guild_id <= 0 then
		return ERROR_GUILD_NO_GUILD
	end

	local guild = _G.getGuild(guild_id)
	if not guild then
		return ERROR_GUILD_NO_GUILD
	end

	if redtype == GUILD_RED_PACKAGE_COMMON then--普通红包
		-- 灵符够不够
		local ret = Entity.checkCapital(player, ITEM_LINGFU, max_gold)
		if ret ~= SUCCESS then
			return ret
		end
	
		local datax = player:getEventDataX(EVENT_HHHB)
		local newVal = datax + max_gold
		if newVal > gdEventData[EVENT_HHHB].datax then
			return ERROR_OVER_MAX_LIMIT
		end
		player:setEventDataX(EVENT_HHHB, newVal)
		player:saveEventData(EVENT_HHHB)
		player:syncEventData(EVENT_HHHB)
	
		return Entity.useCapital(player, ITEM_LINGFU, max_gold, OP_GUILD_SEND_RED)
	elseif redtype == GUILD_RED_PACKAGE_SALARY then--俸禄红包
		local job = player:getProp(ENTITY_PROP_GUILD_POST)
		if job ~= GUILD_POST_MASTER then
			return ERROR_GUILD_AUTHORITY
		end

		-- 俸禄红包，每天发送一个，加上服务器控制
		local lastDay = guild:getProp(GUILD_PROP_SPECIAL_RED_BAG_DAY)
		local curday = getday(os.time())
		if lastDay == curday then
			return ERROR_UNKNOWN
		end

		local guildMoney = guild:getProp(GUILD_PROP_MONEY)
		local canNeedMoney = guildMoney * 0.2--最多消耗公会资金1/5
		local changMoney =  math.floor(canNeedMoney/100) --公会资金与兑换砖石比例 1:100
		if changMoney < max_gold then
			return ERROR_GUILD_NOT_ENOUGH_MONEY
		end
	
		local needCoumseNum = max_gold * 100
		guild:setProp(GUILD_PROP_MONEY, guildMoney - needCoumseNum)
		guild:saveProp(GUILD_PROP_MONEY)
		guild:syncProp(GUILD_PROP_MONEY)
		
		guild:setProp(GUILD_PROP_SPECIAL_RED_BAG_DAY, curday)
		guild:saveProp(GUILD_PROP_SPECIAL_RED_BAG_DAY)
	end

	return SUCCESS
end

function Guild.sendSWZDZAward(guild_id)
	local guild = _G.getGuild(guild_id)
	if not guild then
		--行会不存在
		return ERROR_GUILD_NOT_EXIST
	end
	-- guild:forEach(function(p)
			-- p:addGene(377)
		-- end)
end

-- 根据开服时间获取奖励
function Guild.getSWYRewards(rewardList)
	local rewards = {}
	for i, v in ipairs(rewardList) do
		if gdGame.server_days >= v.startTime and gdGame.server_days < v.endTime then
			table.insert(rewards, v)
		end
	end
	return rewards
end

function Guild.sendGuildActivitySWYRewards(pid, rank, rankType, guidId)
	local rewardList = nil
	local title = nil
	local desc = nil
	if guidId == nil then
		guidId = 0
	end
	if guidId <= 0 then
		return
	end
	if rankType == SWY_RANK_PLAYER then
		title = gdSvrLanguage[412].text
		desc = language.GetText(gdSvrLanguage[413].text, {rank})
		rewardList = Guild.getSWYRewards(gdSwyReward[rank])
	elseif rankType == SWY_RANK_GUILD then
		title = gdSvrLanguage[661].text
		desc = language.GetText(gdSvrLanguage[662].text, {rank})
		rewardList = Guild.getSWYRewards(gdSwyGuildReward[rank])
	end
	if rewardList and title and desc then
		local rewards = {}
		if _G.getWorldDataX(WORLD_PROP_WAR_ZONE_INFO) <= 0 then
			for i, v in ipairs(rewardList) do
				local reward = {}
				reward.counts = v.counts
				reward.bind = v.bind
				reward.itemId = v.itemId
				table.insert(rewards, reward)
			end
		else
			for i, v in ipairs(rewardList) do
				local reward = {}
				reward.counts = v.countsCross
				reward.bind = v.bindCross
				reward.itemId = v.itemIdCross
				table.insert(rewards, reward)
			end
		end
		Entity.sendMail(pid, title,desc, rewards)
	end
end

-- 将物品加入到行会鬼市
function Guild.addGuildItem(entity, sid,isauto)
	-- 如果是8转及以上，则需要加入到行会鬼市
	local itemVo = gdItems[sid]
	if itemVo and itemVo.req_level_type == 1 and itemVo.req_level >= 8 then
		local guild_id = entity:getProp(ENTITY_PROP_GUILD_ID)
		if guild_id > 0 then
			local guild = _G.getGuild(guild_id)
			if guild then
				guild:addGuishiItem(sid)
				
				Guild.checkGuishiItemsSize(guild)
				
				if isauto then
					guild:syncGuishiItems()
				end
			end
		end
	end
end

-- -- 工会鬼市兑换
function Guild.checkGuishiItemsSize(guild)
	if not guild then 
		return 
	end
	
	local items_list = guild:getAllGuishiItems()
	local cnt = #items_list
	if cnt <= 50 then
		return
	end
	
	local _price = 0
	local _cid = 0
	for i, v in ipairs(items_list) do
		local sid = guild:getGuishiItemBycid(v)
		
		if sid and sid > 0 and gdGuildExchangeItem[sid] then
			local data =  gdGuildExchangeItem[sid]
			if _price == 0 then
				_price = data.price
				_cid = v
			else
				if _price >  data.price then
					_price = data.price
					_cid = v
				end
			end
		end
	end
	
	if _cid > 0 then
		guild:delGuishiItem(_cid)
	end
end

--踢出成员发送邮件
function Guild.sendDeleteGuildMemberMail(pid, gid)
	local guild = _G.getGuild(gid)
	if guild then
		local title = gdSvrLanguage[792].text
		local desc = language.GetText(gdSvrLanguage[793].text, {guild:getGuildName()})
		Mail.sendMail(pid, title,desc)
	end
end

--邀请其他公会加入本公会
function Guild.mergeGuildRequest(entity, gid)
	local myGid = entity:getProp(ENTITY_PROP_GUILD_ID)
	local myGuild = _G.getGuild(myGid)
	local otherGuild = _G.getGuild(gid)
	local masterId = otherGuild:getMasterPid()
	local master = _G.getPlayer(masterId)

	if not myGuild or not otherGuild then
		return ERROR_UNKNOWN
	end

	local my_declear_id = myGuild:getProp(GUILD_PROP_DECLARE_WAR_GUILD)
	local other_declear_id = otherGuild:getProp(GUILD_PROP_DECLARE_WAR_GUILD)
	if my_declear_id ~= 0 or other_declear_id ~= 0 then -- 其中一个行会向其他行会发起宣战
		return ERROR_DECLARE_NOT_MERGE
	end

	local has_decleared = false
	_G.forEachGuild(function (guild) -- 有行会向其中一个行会发起宣战
		local declear_id = guild:getProp(GUILD_PROP_DECLARE_WAR_GUILD)
		if declear_id == myGid or declear_id == gid then
			has_decleared = true
		end
	end)
	if has_decleared then
		return ERROR_DECLARE_NOT_MERGE
	end

	if not master then
		entity:svrToClient(FUNC_MERGE_GUILD, 1) --会长不在线不能邀请
		return
	end
	local mergeStr = master:getStringProp(ENTITY_STRPROP_GUILD_MERGE_DATA)
	local arr = Split(mergeStr,";")
	for i, v in ipairs(arr) do
		local arr2 = Split(v,",")
		if arr2[1] == tostring(myGid) then
			entity:svrToClient(FUNC_MERGE_GUILD, 2) --已经邀请，等待对方回复
			return 
		end
	end
	local allMemberCounts = otherGuild:getMemberCount() + myGuild:getMemberCount()
	local myLevel = myGuild:getProp(GUILD_PROP_LEVEL)
	local guildLevelData = gdGuildLevelDatas[myLevel]
	if not guildLevelData then
		return
	end
	local maxCount = guildLevelData.guildNum
	if maxCount < allMemberCounts then
		entity:svrToClient(FUNC_MERGE_GUILD, 3) --公会人数超上限
		return
	end
	if not Event.isGuildActivityTime(entity) then --公会活动期间不能邀请
		return
	end

	if mergeStr == "" then
		mergeStr = myGid .. "," .. myGuild:getGuildName() .. "," .. entity:getName()
	else
		mergeStr = mergeStr .. ";" .. myGid .. "," .. myGuild:getGuildName() .. "," .. entity:getName()
	end
	master:setStringProp(ENTITY_STRPROP_GUILD_MERGE_DATA, mergeStr)
	master:saveStringProp(ENTITY_STRPROP_GUILD_MERGE_DATA)
	master:syncStringProp(ENTITY_STRPROP_GUILD_MERGE_DATA)
	entity:svrToClient(FUNC_MERGE_GUILD, 0) --邀请成功，等待对方回复
	_G.sendMail(masterId, gdSvrLanguage[796].text,language.GetText(gdSvrLanguage[797].text, {myGuild:getGuildName(), entity:getName()}))
end

--本公会加入其他公会
function Guild.mergeGuildResponse(entity, gid, agree)
	local myPid = entity:getGlobalID()
	local myGid = entity:getProp(ENTITY_PROP_GUILD_ID)
	local myGuild = _G.getGuild(myGid)
	local otherGuild = _G.getGuild(gid)
	if agree == 1 then
		if not myGuild or not otherGuild then
			return ERROR_UNKNOWN
		end

		local my_declear_id = myGuild:getProp(GUILD_PROP_DECLARE_WAR_GUILD)
		local other_declear_id = otherGuild:getProp(GUILD_PROP_DECLARE_WAR_GUILD)
		if my_declear_id ~= 0 or other_declear_id ~= 0 then -- 其中一个行会向其他行会发起宣战
			return ERROR_DECLARE_NOT_MERGE
		end
	
		local has_decleared = false
		_G.forEachGuild(function (guild) -- 有行会向其中一个行会发起宣战
			local declear_id = guild:getProp(GUILD_PROP_DECLARE_WAR_GUILD)
			if declear_id == myGid or declear_id == gid then
				has_decleared = true
			end
		end)
		if has_decleared then
			return ERROR_DECLARE_NOT_MERGE
		end

		local allMemberCounts = otherGuild:getMemberCount() + myGuild:getMemberCount()
		local otherLevel = otherGuild:getProp(GUILD_PROP_LEVEL)
		local guildLevelData = gdGuildLevelDatas[otherLevel]
		if not guildLevelData then
			return
		end
		local maxCount = guildLevelData.guildNum
		if maxCount < allMemberCounts then
			entity:svrToClient(FUNC_MERGE_GUILD, 3) --公会人数超上限
			return
		end
		if not Event.isGuildActivityTime(entity) then --公会活动期间不能邀请
			return
		end
		_G.mergeGuild(myGid, gid)
		entity:setStringProp(ENTITY_STRPROP_GUILD_MERGE_DATA, "")
		entity:saveStringProp(ENTITY_STRPROP_GUILD_MERGE_DATA)
		entity:syncStringProp(ENTITY_STRPROP_GUILD_MERGE_DATA)
	else
		local masterId = otherGuild:getMasterPid()
		local master = _G.getPlayer(masterId)
		if master then
			master:svrToClient(FUNC_MERGE_GUILD, 4, 0, 0, myGuild:getGuildName()) --拒绝了合并行会请求
		end
		_G.sendMail(masterId, gdSvrLanguage[798].text,language.GetText(gdSvrLanguage[799].text, {myGuild:getGuildName(), entity:getName()}))
		local mergeStr = entity:getStringProp(ENTITY_STRPROP_GUILD_MERGE_DATA)
		local arr = Split(mergeStr,";")
		local newMergeStr = ""
		for i, v in ipairs(arr) do
			if Split(v,",")[1] ~= tostring(gid) then
				if newMergeStr == "" then
					newMergeStr = v
				else
					newMergeStr = newMergeStr .. ";" .. v
				end
			end
		end

		entity:setStringProp(ENTITY_STRPROP_GUILD_MERGE_DATA,newMergeStr)
		entity:saveStringProp(ENTITY_STRPROP_GUILD_MERGE_DATA)
		entity:syncStringProp(ENTITY_STRPROP_GUILD_MERGE_DATA)
	end

	return SUCCESS
end

function Guild.sendMergeGuildSuccessMail(pid, guildName)
	_G.sendMail(pid, gdSvrLanguage[800].text,language.GetText(gdSvrLanguage[801].text, {guildName, guildName}))
end
 
-- 玩家职位变更
function Guild.onGuildPostChange(entity, prePost, curPost)
	-- if not entity then
    --     return
    -- end
	-- -- local guild = _G.getGuild(entity:getProp(ENTITY_PROP_GUILD_ID))
    -- -- if guild == nil then
	-- -- 	entity:setProp(ENTITY_PROP_GUILD_POST, 0)
    -- --     return
    -- -- end
	-- if prePost == curPost then
	-- 	return
	-- end
    -- local cbt = entity:getCombatSys()
    -- if not cbt then
    --     return
    -- end
	-- -- 移除旧属性
	-- local preAttrConfig = gdGuildPosAttrDatas[prePost]
	-- if preAttrConfig then
	-- 	for k, v in pairs(preAttrConfig.attr) do
	-- 		Combat.rmvAttr(cbt, v)
	-- 	end
	-- end
	-- -- 新增新属性
	-- local curAttrConfig = gdGuildPosAttrDatas[curPost]
	-- if curAttrConfig then
	-- 	for k, v in pairs(curAttrConfig.attr) do
	-- 		Combat.addAttr(cbt, v)
	-- 	end
    -- end

    -- entity:syncPlayerCombatCombo()
end

-- 行会更新
function Guild.onUpdateOneGuild(guild)
	local declear_over_time = guild:getProp(GUILD_PROP_DECLARE_WAR_OVER_TIME)
	if declear_over_time == 0 then
		return
	end

	if declear_over_time <= os.time() then
		guild:setProp(GUILD_PROP_DECLARE_WAR_OVER_TIME, 0)
		guild:saveProp(GUILD_PROP_DECLARE_WAR_OVER_TIME)
		guild:syncProp(GUILD_PROP_DECLARE_WAR_OVER_TIME)

		guild:setProp(GUILD_PROP_DECLARE_WAR_GUILD, 0)
		guild:saveProp(GUILD_PROP_DECLARE_WAR_GUILD)
		guild:syncProp(GUILD_PROP_DECLARE_WAR_GUILD)

		guild:forEach(function(member)
			member:setProp(ENTITY_PROP_DECLARE_GUILD_ID, 0)
			member:saveProp(ENTITY_PROP_DECLARE_GUILD_ID)
			member:syncProp(ENTITY_PROP_DECLARE_GUILD_ID)
		end)
	end
end

-- 行会更新
function Guild.onUpdateAllData()
    _G.forEachGuild(Guild.onUpdateOneGuild)
end

-- 行会宣战
function Guild.onDeclareGuildRequest(entity, gid)
	local myGid = entity:getProp(ENTITY_PROP_GUILD_ID)
	local myGuild = _G.getGuild(myGid)
	local otherGuild = _G.getGuild(gid)

	if not myGuild or not otherGuild then
		return ERROR_DECLARE_NOT
	end

	local my_declear_id = myGuild:getProp(GUILD_PROP_DECLARE_WAR_GUILD)
	if my_declear_id ~= 0 then
		return ERROR_DECLARE_ONLY_ONE
	end

	local my_declear_times = myGuild:getProp(GUILD_PROP_DECLARE_WAR_TIMES)
	if my_declear_times >= gdGuildDeclareWarDatas.daily_times then
		return ERROR_DECLARE_NO_TIMES
	end

	if not entity:hasItem(gdGuildDeclareWarDatas.cost_item.sid, gdGuildDeclareWarDatas.cost_item.count) or
		Entity.getCapital(entity, gdGuildDeclareWarDatas.cost_capital.sid) < gdGuildDeclareWarDatas.cost_capital.count then
		return
	end

	Entity.useCapital(entity, gdGuildDeclareWarDatas.cost_capital.sid, gdGuildDeclareWarDatas.cost_capital.count, OP_GUILD_DECLEAR_WAR)
	entity:rmvItem(gdGuildDeclareWarDatas.cost_item.sid, gdGuildDeclareWarDatas.cost_item.count, BAG_TYPE_PLAYER, OP_GUILD_DECLEAR_WAR)

	local over_time = os.time() + gdGuildDeclareWarDatas.last_time
	myGuild:setProp(GUILD_PROP_DECLARE_WAR_OVER_TIME, over_time)
	myGuild:saveProp(GUILD_PROP_DECLARE_WAR_OVER_TIME)
	myGuild:syncProp(GUILD_PROP_DECLARE_WAR_OVER_TIME)
	myGuild:setProp(GUILD_PROP_DECLARE_WAR_TIMES, my_declear_times + 1)
	myGuild:saveProp(GUILD_PROP_DECLARE_WAR_TIMES)
	myGuild:syncProp(GUILD_PROP_DECLARE_WAR_TIMES)
	myGuild:setProp(GUILD_PROP_DECLARE_WAR_GUILD, gid)
	myGuild:saveProp(GUILD_PROP_DECLARE_WAR_GUILD)
	myGuild:syncProp(GUILD_PROP_DECLARE_WAR_GUILD)
	entity:svrToClient(FUNC_DECLARE_WAR, 0) --宣战成功

	myGuild:forEach(function(member)
		local member_pid = member:getGlobalID()
		member:setProp(ENTITY_PROP_DECLARE_GUILD_ID, gid)
		member:saveProp(ENTITY_PROP_DECLARE_GUILD_ID)
		member:syncProp(ENTITY_PROP_DECLARE_GUILD_ID)
		_G.sendMail(member_pid, gdSvrLanguage[831].text,language.GetText(gdSvrLanguage[832].text, {otherGuild:getGuildName()}))
	end)
	
	otherGuild:forEachPlayerID(function(member_pid)
		_G.sendMail(member_pid, gdSvrLanguage[831].text,language.GetText(gdSvrLanguage[832].text, {myGuild:getGuildName()}))
	end)

	-- 行会宣战 世界通知
	_G.syncFloatMessage(language.GetText(gdSvrLanguage[837].text, {
		myGuild:getGuildName(),
		otherGuild:getGuildName()
	}))
end

-- 行会跨天刷新
function Guild.onServerDayChange()
	_G.forEachGuild(function (guild)
		guild:setProp(GUILD_PROP_DECLARE_WAR_TIMES, 0)
		guild:saveProp(GUILD_PROP_DECLARE_WAR_TIMES)
		guild:syncProp(GUILD_PROP_DECLARE_WAR_TIMES)
	end)
end
