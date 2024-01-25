-- 技能消息id
SKILL_EVENT_ID = {
    NEXT_PHASE = 1,
    FLASH_DEL = 2,
    DESTROY = 3
}

-- 技能规则id
SKILL_RULE_ID = {
    RULE_FOUR_PHASE       = 1,  -- 四个阶段[灵魂火符...]
    RULE_THREE_PHASE      = 2,  -- 三个阶段[万毒噬天、施毒术...]
    RULE_LU_LEI           = 3,  -- 雷电术
    RULE_MO_DUN           = 4,  -- 魔法盾
    RULE_BING_PAO_XIAO    = 5,  -- 冰咆哮
    RULE_HUO_QIANG        = 6,  -- 火墙
    RULE_DI_YU_LEI_GUA    = 7,  -- 地狱雷光
    RULE_BASE_SKILL_DS    = 8,  -- 道士基础技能（普通火符）
    RULE_BASE_SKILL_FS    = 9,  -- 法师基础技能（普通火球）
    RULE_CHONG_ZHUANG     = 10, -- 冲撞
    RULE_YING_SHEN        = 11, -- 隐身
    RULE_KANG_JU          = 12, -- 抗拒
    RULE_MO_JIA           = 13, -- 魔甲
    RULE_JTBF             = 14, -- 剑荡八方
    RULE_MON_THR          = 15, -- 怪物技能3
    RULE_MON_1            = 16, -- 怪物技能 受击
    RULE_MON_2            = 17, -- 怪物技能 攻击 + 受击
    RULE_MON_3            = 18, -- 怪物技能 飞行
    RULE_MON_4            = 19, -- 怪物技能 攻击 + 飞行 + 受击
    RULE_SKILL_1          = 20, -- 受击
    RULE_SKILL_2          = 21, -- 受击
    RULE_SKILL_3          = 22, -- 飞行 + 受击
    RULE_SKILL_4          = 23, -- 人剑合一
    RULE_SKILL_5          = 24, -- 攻击技能
    RULE_SKILL_6          = 25,
    RULE_SKILL_7          = 26,
    RULE_SKILL_8          = 27,
    RULE_SKILL_9          = 28, -- 野蛮冲撞
    RULE_SKILL_10         = 30,
    RULE_SKILL_11         = 31,
    RULE_SKILL_12         = 32,
    RULE_SKILL_13         = 33,
    RULE_HEJI             = 34,    -- 合击技能
    RULE_SKILL_SELF_CNT   = 35,    -- 霸道火雨随机点释放
    RULE_HEJI_BDHY        = 36,    -- 合击技能
    RULE_SCREEN_MON_SKILL = 37,    -- 以怪物为中心的全屏技能
    RULE_FALIJJ           = 38,    -- 法力荆棘
    RULE_NO_ATCION_SKILL  = 39,    -- 无动作技能
    RULE_SKILL_HBZ        = 40,    -- 寒冰掌
    RULE_SKILL_SXS        = 41,    -- 嗜血术
    RULE_SKILL_KB         = 42,    -- 狂暴
    RULE_SKILL_SBYS       = 43,    -- 十步一杀
    RULE_SKILL_MTH        = 44,    -- 灭天火
    RULE_SKILL_QLS        = 45,    -- 擒龙手
    RULE_SKILL_YMFZ       = 46,    -- 幽冥符咒
    RULE_SKILL_HTMD       = 47,    -- 毁天灭地
    RULE_TWO_PHASE_DUN    = 48,    -- 两阶段护盾[幽灵盾、神圣战甲术]
    RULE_SKILL_JFP        = 49,    --飓风破
    RULE_SKILL_WJZQ       = 50,    --无极真气
    RULE_SKILL_HTSD       = 51,    --护体神盾
    RULE_SKILL_QTYS       = 52,    --群体隐身
    RULE_SKILL_ZHKL       = 53,    --召唤骷髅
    RULE_SKILL_QTZL       = 54,    --群体治疗术
    RULE_SKILL_YINSHEN    = 55,    --隐身
    RULE_SKILL_ZHILIAO    = 56,    --治疗

    RULE_BE_ATK_1         = 10000, -- 被攻击1
    RULE_BE_ATK_2         = 10001  -- 被攻击2

}

-- 技能显示位置
SKILL_SHOW_LOCAL = {
    host              = 1, -- 宿主身上
    aim               = 2, -- 敌人身上
    scene_host        = 3, -- 场景
    scene_aim         = 4, -- 场景
    scene_pos         = 5, -- 场景上的某个点
    scene_host_around = 6  -- 宿主周围的场景上的点
}

-- 技能深度位置
SKILL_ORDER = {
    player_dowm = 1, -- 人物下面
    player_up   = 2, -- 人物上面
    scene_h     = 3, -- 场景和宿主一样 宿主下面
    scene_u     = 4, -- 场景和宿主一眼 宿主上面
    scene_top   = 5, -- 场景顶层
    scene_low   = 6, -- 场景最低层
    player_dir  = 7,
    default     = 0
}

-- 技能规则
SKILL_RULE = {
    moment       = 1,  -- 阶段
    show         = 2,  -- 显示位置
    delay        = 3,  -- 当前阶段延迟   只有在初始有效
    nextDelay    = 4,  -- 下一阶段延迟
    zorder       = 5,  -- 深度位置
    position     = 10, -- 第二位置 从敌人和宿主选择
    buff         = 11, -- 宿主身上的buff
    move         = 12, -- 移动                --[[ 注意 ： move 和 nextdelay 只能存在一个 ]]
    skewY        = 14, -- 偏移Y
    message      = 15, -- 向服务器发送消息
    actDir       = 16, -- 1跟随主人的方向 2敌人方向
    skew_y_high2 = 18, -- 偏移量y高度取人物的高度一般
    posMessage   = 20, -- 地面消息
    vertical     = 21, -- 垂直
    offsetY      = 22, -- 初始偏移Y
    startVisf    = 23, -- 初始是否消失
    start_msg    = 24, -- 开始验证消息
    isHero       = 25, -- 英雄的时候 不需要往下走
    showWord     = 26, -- 显示大字报
    shakeScreen  = 27, -- 震屏
    randPos      = 28, -- 随机点
    savePos      = 29, -- 保存点
    offset       = 30, -- 偏移坐标
    scale        = 31, -- 缩放
    spgogo       = 32, -- 旋转90°调整角度
    Xsymmetry    = 33, -- x轴对称
    Ysymmetry    = 34, -- y轴对称
    delayMessage = 35  -- 向服务器发送消息
}

SKILL_REG = {
    phase1     = 1, -- 起手
    phase2     = 2, -- 收手
    phase3     = 3, -- 飞行
    phase4     = 4, -- 受击
    phase      = 5, -- 阶段数量
    buff_phase = 6, -- buff阶段
    buff_type  = 7  -- buff类型
}

-- 特效位置
SKILL_EFFECT_MOMENT = {}
SKILL_EFFECT_MOMENT[SKILL_REG.phase1] = "effect_src"  -- 起手
SKILL_EFFECT_MOMENT[SKILL_REG.phase2] = "effect_srcx" -- 收手
SKILL_EFFECT_MOMENT[SKILL_REG.phase3] = "effect_mid"  -- 飞行
SKILL_EFFECT_MOMENT[SKILL_REG.phase4] = "effect_tgt"  -- 受击

-- 技能注册
SKILL_REGISTER = {}

--------------------------------------------四个阶段有特效--------------------------------------------------
-- 四个阶段都有[灵魂火符...]
SKILL_REGISTER[SKILL_RULE_ID.RULE_FOUR_PHASE] = {
    [SKILL_REG.phase] = 4,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_dowm,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.1,
        [SKILL_RULE.message] = 1
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase2,
        [SKILL_RULE.nextDelay] = 0.1
    },
    [3] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase3,
        [SKILL_RULE.move] = 0.4,
        [SKILL_RULE.skewY] = 0.1,
        [SKILL_RULE.startVisf] = 1

    },
    [4] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase4,
        [SKILL_RULE.skew_y_high2] = 1
    }
}


--------------------------------------------三个阶段有特效--------------------------------------------------
-- 三个阶段，没有飞行动作[万毒噬天、施毒术...]
SKILL_REGISTER[SKILL_RULE_ID.RULE_THREE_PHASE] = {
    [SKILL_REG.phase] = 3,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_dowm,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0,
        [SKILL_RULE.message] = 1
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase2,
        [SKILL_RULE.nextDelay] = 0.3
    },
    [3] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.moment] = SKILL_REG.phase4,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top
    }
}


-- 三个阶段，飞行动作[普通火符]
SKILL_REGISTER[SKILL_RULE_ID.RULE_BASE_SKILL_DS] = {
    [SKILL_REG.phase] = 3,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_down,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0,
        [SKILL_RULE.message] = 1
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase3,
        [SKILL_RULE.move] = 0.4,
        [SKILL_RULE.skewY] = 0.1,
        [SKILL_RULE.startVisf] = 1
    },
    [3] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase4,
        [SKILL_RULE.skew_y_high2] = 1
    }
}

-- 三个阶段，飞行动作[普通火球]
SKILL_REGISTER[SKILL_RULE_ID.RULE_BASE_SKILL_FS] = {
    [SKILL_REG.phase] = 3,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.2,
        [SKILL_RULE.message] = 1
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase3,
        [SKILL_RULE.move] = 0.4,
        [SKILL_RULE.skewY] = 0.1,
        [SKILL_RULE.startVisf] = 1
    },
    [3] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase4,
        [SKILL_RULE.skew_y_high2] = 1
    }
}

--------------------------------------------二个阶段有特效--------------------------------------------------
-- 两个阶段，起手和被击[雷电术...]
SKILL_REGISTER[SKILL_RULE_ID.RULE_LU_LEI] = {
    [SKILL_REG.phase] = 2,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_dowm,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.2,
        [SKILL_RULE.message] = 1
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase4
    }
}

-- 两个阶段，起手和被击，增加消息验证[冰咆哮...]
SKILL_REGISTER[SKILL_RULE_ID.RULE_BING_PAO_XIAO] = {
    [SKILL_REG.phase] = 2,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.3,
        [SKILL_RULE.start_msg] = 1

    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase4,
        [SKILL_RULE.message] = 1
    }
}

--------------------------------------------一个阶段有特效--------------------------------------------------
-- 一个阶段，什么动作都没有，只发消息
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_HTSD] = {
    [SKILL_REG.phase] = 1,
    [SKILL_REG.buff_type] = ALIVER_CLOTH_TYPE.SKILL_MIT,
    [1] = {
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.posMessage] = 1
    }
}

-- 一个阶段，只有起手动作，延迟一秒发消息
SKILL_REGISTER[SKILL_RULE_ID.RULE_MO_DUN] = {
    [SKILL_REG.phase] = 1,
    [SKILL_REG.buff_type] = ALIVER_CLOTH_TYPE.SKILL_MIT,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.delayMessage] = 1
    }
}

-- 一个阶段，在场景上显示特效[火墙...]
SKILL_REGISTER[SKILL_RULE_ID.RULE_HUO_QIANG] = {
    [SKILL_REG.phase] = 1,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_h,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.posMessage] = 1
    }
}

-- 一个阶段，在场景上显示特效
SKILL_REGISTER[SKILL_RULE_ID.RULE_DI_YU_LEI_GUA] = {
    [SKILL_REG.phase] = 1,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_low,
        [SKILL_RULE.moment] = SKILL_REG.phase1
    },
}

-- 音波功
SKILL_REGISTER[SKILL_RULE_ID.RULE_MON_THR] = {
    [SKILL_REG.phase] = 3,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0,
        [SKILL_RULE.start_msg] = 1
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase3,
        [SKILL_RULE.move] = 1,
        [SKILL_RULE.skewY] = 0.4,
        [SKILL_RULE.startVisf] = 1
    },
    [3] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.aim,
        [SKILL_RULE.moment] = SKILL_REG.phase4,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.message] = 1
    }
}

-- 合击
SKILL_REGISTER[SKILL_RULE_ID.RULE_HEJI] = {
    [SKILL_REG.phase] = 2,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.3,
        [SKILL_RULE.start_msg] = 1,
        [SKILL_RULE.showWord] = 1
    },
    [2] = {
        [SKILL_RULE.isHero] = 0,
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase4,
        [SKILL_RULE.message] = 1,
        [SKILL_RULE.shakeScreen] = 1
    }
}

-- 合击霸道火雨
SKILL_REGISTER[SKILL_RULE_ID.RULE_HEJI_BDHY] = {
    [SKILL_REG.phase] = 2,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0,
        [SKILL_RULE.start_msg] = 1,
        [SKILL_RULE.showWord] = 1
    },
    [2] = {
        [SKILL_RULE.isHero] = 0,
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_dir,
        [SKILL_RULE.moment] = SKILL_REG.phase4,
        [SKILL_RULE.message] = 1,
        [SKILL_RULE.actDir] = 1,
        [SKILL_RULE.shakeScreen] = 1
    }
}

-- 超级触龙神的全屏毒技能
SKILL_REGISTER[SKILL_RULE_ID.RULE_SCREEN_MON_SKILL] = {
    [SKILL_REG.phase] = 9,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host_around,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.offset] = { 450, 0 },
        [SKILL_RULE.nextDelay] = 0,
        [SKILL_RULE.moment] = SKILL_REG.phase1
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host_around,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.offset] = { -450, 0 },
        [SKILL_RULE.nextDelay] = 0,
        [SKILL_RULE.moment] = SKILL_REG.phase1
    },
    [3] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host_around,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.offset] = { 0, 250 },
        [SKILL_RULE.nextDelay] = 0,
        [SKILL_RULE.moment] = SKILL_REG.phase1
    },
    [4] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host_around,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.offset] = { 0, -230 },
        [SKILL_RULE.nextDelay] = 0,
        [SKILL_RULE.moment] = SKILL_REG.phase1
    },
    [5] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host_around,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.offset] = { 300, 205 },
        [SKILL_RULE.nextDelay] = 0,
        [SKILL_RULE.moment] = SKILL_REG.phase1
    },
    [6] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host_around,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.offset] = { 300, -205 },
        [SKILL_RULE.nextDelay] = 0,
        [SKILL_RULE.moment] = SKILL_REG.phase1
    },
    [7] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host_around,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.offset] = { -300, 205 },
        [SKILL_RULE.nextDelay] = 0,
        [SKILL_RULE.moment] = SKILL_REG.phase1
    },
    [8] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host_around,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.offset] = { -300, -205 },
        [SKILL_RULE.nextDelay] = 0,
        [SKILL_RULE.moment] = SKILL_REG.phase1
    },
    [9] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host_around,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_dowm,
        [SKILL_RULE.offset] = { 0, -40 },
        [SKILL_RULE.scale] = { 2.5, 2.5 },
        [SKILL_RULE.moment] = SKILL_REG.phase1
    }
}

-- 剑荡八方
SKILL_REGISTER[SKILL_RULE_ID.RULE_JTBF] = {
    [SKILL_REG.phase] = 2,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_dowm,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0,
        [SKILL_RULE.start_msg] = 1

    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase4,
        [SKILL_RULE.message] = 1
    }
}

-- --法力荆棘
SKILL_REGISTER[SKILL_RULE_ID.RULE_FALIJJ] = {
    [SKILL_REG.phase] = 1,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1
        -- [SKILL_RULE.message]    = 1,

    }
}

-- 狂暴
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_KB] = {
    [SKILL_REG.phase] = 1,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.message] = 1

    }
}

-- 战神冲撞
SKILL_REGISTER[SKILL_RULE_ID.RULE_CHONG_ZHUANG] = {
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_dir,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.actDir] = 1
    },
    [SKILL_REG.phase] = 1
}

-- 自己隐遁术
SKILL_REGISTER[SKILL_RULE_ID.RULE_YING_SHEN] = {
    [SKILL_REG.phase] = 1,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1
        -- [SKILL_RULE.start_msg]  = 1,
    }
}

-- 火焰抗拒
SKILL_REGISTER[SKILL_RULE_ID.RULE_KANG_JU] = {
    [SKILL_REG.phase] = 1,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.default,
        [SKILL_RULE.moment] = SKILL_REG.phase1
    }
}

-- 幽灵魔甲术
SKILL_REGISTER[SKILL_RULE_ID.RULE_MO_JIA] = {
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.position] = SKILL_SHOW_LOCAL.host
    }
}

-- 怪物技能 收击
SKILL_REGISTER[SKILL_RULE_ID.RULE_MON_1] = {
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase4
    },
    [SKILL_REG.phase] = 1
}

-- 怪物技能 攻击 + 受击
SKILL_REGISTER[SKILL_RULE_ID.RULE_MON_2] = {
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_dir,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0,
        [SKILL_RULE.actDir] = 1
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase4
    },
    [SKILL_REG.phase] = 2
}

-- 怪物技能 飞行
SKILL_REGISTER[SKILL_RULE_ID.RULE_MON_3] = {
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase3,
        [SKILL_RULE.move] = 1,
        [SKILL_RULE.delay] = 0.2,
        [SKILL_RULE.skewY] = 0.4,
        [SKILL_RULE.startVisf] = 1
    },
    [SKILL_REG.phase] = 1
}

-- 怪物技能 攻击 + 飞行 + 受击
SKILL_REGISTER[SKILL_RULE_ID.RULE_MON_4] = {
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_dir,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0,
        [SKILL_RULE.actDir] = 1
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase3,
        [SKILL_RULE.move] = 1,
        [SKILL_RULE.vertical] = 1,
        [SKILL_RULE.offsetY] = 300,
        [SKILL_RULE.startVisf] = 1
    },
    [3] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase4
    },
    [SKILL_REG.phase] = 3
}

-- 怪物技能 受击
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_1] = {
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.message] = 1
    },
    [SKILL_REG.phase] = 1
}

-- 怪物技能 收击
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_2] = {
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.message] = 1
    },
    [SKILL_REG.phase] = 1
}

-- 怪物技能 飞行 + 受击
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_3] = {
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase3,
        [SKILL_RULE.move] = 1,
        [SKILL_RULE.spgogo] = 1,
        [SKILL_RULE.startVisf] = 1
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase4,
        [SKILL_RULE.message] = 1
    },
    [SKILL_REG.phase] = 2
}

-- 地狱雷光
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_4] = {
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.message] = 1,
        [SKILL_RULE.actDir] = 1
    },
    [SKILL_REG.phase] = 1
}

-- 无攻击动作
SKILL_REGISTER[SKILL_RULE_ID.RULE_NO_ATCION_SKILL] = {
    [1] = {
        [SKILL_RULE.message] = 1,
        -- [SKILL_RULE.show]       = SKILL_SHOW_LOCAL.scene_host,
        -- [SKILL_RULE.zorder]     = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase1
        -- [SKILL_RULE.actDir]		= 1,
    },
    [SKILL_REG.phase] = 1
}

-- 攻击技能
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_5] = {
    [1] = {
        [SKILL_RULE.message] = 1,
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.actDir] = 1

    },
    [SKILL_REG.phase] = 1
}

-- 技能
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_6] = {
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_low,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.actDir] = 1
    },
    [SKILL_REG.phase] = 1
}

-- 怪物技能 飞行
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_7] = {
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase3,
        [SKILL_RULE.move] = 1,
        [SKILL_RULE.delay] = 0.5,
        [SKILL_RULE.offsetY] = 20,
        [SKILL_RULE.startVisf] = 1
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase4,
        [SKILL_RULE.message] = 1
    },
    [SKILL_REG.phase] = 2
}

SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_8] = {
    [SKILL_REG.phase] = 2,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_low,
        [SKILL_RULE.moment] = SKILL_REG.phase3
    }
}

-- 十步一杀
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_SBYS] = {
    [SKILL_REG.phase] = 2,
    [1] = {
        [SKILL_RULE.posMessage] = 1,
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.delay] = 0.2,
        [SKILL_RULE.nextDelay] = 0.1
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_dowm,
        [SKILL_RULE.moment] = SKILL_REG.phase2
    }
}

-- 野蛮冲撞
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_9] = {
    [1] = {
        [SKILL_RULE.posMessage] = 1,
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.actDir] = 1
    },
    [SKILL_REG.phase] = 1
}

--
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_10] = {
    [SKILL_REG.phase] = 2,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0,
        [SKILL_RULE.actDir] = 1
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_low,
        [SKILL_RULE.moment] = SKILL_REG.phase4
    }
}

-- 2个受击，1个在受击上方1个在场景上方
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_11] = {
    [SKILL_REG.phase] = 2,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_low,
        [SKILL_RULE.moment] = SKILL_REG.phase3
    }
}

-- 2个攻击，1个在受击上方1个在场景上方
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_12] = {
    [SKILL_REG.phase] = 2,
    [1] = {
        [SKILL_RULE.message] = 1,
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.actDir] = 1,
        [SKILL_RULE.nextDelay] = 0
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_low,
        [SKILL_RULE.moment] = SKILL_REG.phase3,
        [SKILL_RULE.actDir] = 1
    }

}

-- 擒龙手
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_QLS] = {
    [SKILL_REG.phase] = 4,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.1,
        [SKILL_RULE.message] = 1
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase3,
        [SKILL_RULE.spgogo] = 1,
        [SKILL_RULE.move] = 1
    },
    [3] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.moment] = SKILL_REG.phase4,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.nextDelay] = 0.2,
        [SKILL_RULE.actDir] = 1
    },

    [4] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase2,
        [SKILL_RULE.actDir] = 1
    }
}

-- 灭天火
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_MTH] = {
    [SKILL_REG.phase] = 2,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.3,
        [SKILL_RULE.message] = 1
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase4
    }
}

-- 施法+点选
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_13] = {
    [SKILL_REG.phase] = 2,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.6,
        [SKILL_RULE.message] = 1
        -- [SKILL_RULE.start_msg]  = 2,
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_pos,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase4
    }
}

SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_SELF_CNT] = {
    [SKILL_REG.phase] = 5,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.3,
        [SKILL_RULE.randPos] = 1,
        [SKILL_RULE.posMessage] = 1,
        [SKILL_RULE.savePos] = 1
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_pos,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.4,
        [SKILL_RULE.randPos] = 1
    },
    [3] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_pos,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.3,
        [SKILL_RULE.randPos] = 1
    },
    [4] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_pos,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.5,
        [SKILL_RULE.randPos] = 1
    },
    [5] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_pos,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.3,
        [SKILL_RULE.randPos] = 1
    },
    [6] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_pos,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.2,
        [SKILL_RULE.randPos] = 1
    },
    [7] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_pos,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.3,
        [SKILL_RULE.randPos] = 1
    },
    [8] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_pos,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.3,
        [SKILL_RULE.randPos] = 1
    }
}

-- 寒冰掌
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_HBZ] = {
    [SKILL_REG.phase] = 3,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.2,
        [SKILL_RULE.message] = 1
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase3,
        [SKILL_RULE.spgogo] = 1,
        [SKILL_RULE.move] = 0.5
        -- [SKILL_RULE.skewY]		= 0.4,
        -- [SKILL_RULE.startVisf]  = 1,
    },
    [3] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.aim,
        [SKILL_RULE.moment] = SKILL_REG.phase4,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up

    }
}

-- 飓风破
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_JFP] = {
    [SKILL_REG.phase] = 1,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.aim,
        [SKILL_RULE.moment] = SKILL_REG.phase4,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.message] = 1
    }
}

-- 无极真气
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_WJZQ] = {
    [SKILL_REG.phase] = 1,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.moment] = SKILL_REG.phase2,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.message] = 1
    },
}

-- 幽冥符咒
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_YMFZ] = {
    [SKILL_REG.phase] = 3,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_dowm,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.2,
        [SKILL_RULE.message] = 1
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase3,
        [SKILL_RULE.spgogo] = 1,
        [SKILL_RULE.move] = 0.5
        -- [SKILL_RULE.skewY]		= 0.4,
        -- [SKILL_RULE.startVisf]  = 1,
    },
    [3] = {
        -- [SKILL_RULE.show]       = SKILL_SHOW_LOCAL.aim,
        -- [SKILL_RULE.moment]		= SKILL_REG.phase4,
        -- [SKILL_RULE.zorder]     = SKILL_ORDER.player_up,
        -- [SKILL_RULE.skew_y_high2] = 1,
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase4,
        [SKILL_RULE.skew_y_high2] = 1
    }
}

-- 嗜血术
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_SXS] = {
    [SKILL_REG.phase] = 1,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.moment] = SKILL_REG.phase4,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.nextDelay] = 0.2,
        [SKILL_RULE.message] = 1
    },

}

-- 毁天灭地
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_HTMD] = {
    [SKILL_REG.phase] = 2,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.2,
        [SKILL_RULE.message] = 1
    },

    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase4

    }
}

-- 两阶段护盾[幽灵盾、神圣战甲术]
SKILL_REGISTER[SKILL_RULE_ID.RULE_TWO_PHASE_DUN] = {
    [SKILL_REG.phase] = 2,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.3,
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase4,
        [SKILL_RULE.message] = 1
    }
}

-- 群体隐身
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_QTYS] = {
    [SKILL_REG.phase] = 1,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_pos,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.posMessage] = 1
    }
}

-- 隐身
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_YINSHEN] = {
    [SKILL_REG.phase] = 1,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.posMessage] = 1
    }
}

-- 召唤骷髅
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_ZHKL] = {
    [SKILL_REG.phase] = 2,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.3,
        [SKILL_RULE.message] = 1
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase4
    }
}

-- 群体治疗术
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_QTZL] = {
    [SKILL_REG.phase] = 1,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_pos,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase4,
        [SKILL_RULE.posMessage] = 1
    }
}

-- 治疗术
SKILL_REGISTER[SKILL_RULE_ID.RULE_SKILL_ZHILIAO] = {
    [SKILL_REG.phase] = 2,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_dowm,
        [SKILL_RULE.moment] = SKILL_REG.phase1,
        [SKILL_RULE.nextDelay] = 0.1,
        [SKILL_RULE.message] = 1
    },
    [2] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.scene_aim,
        [SKILL_RULE.zorder] = SKILL_ORDER.scene_top,
        [SKILL_RULE.moment] = SKILL_REG.phase4
    }
}

SKILL_REGISTER[SKILL_RULE_ID.RULE_BE_ATK_1] = {
    [SKILL_REG.phase] = 1,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase4
    }
}

SKILL_REGISTER[SKILL_RULE_ID.RULE_BE_ATK_2] = {
    [SKILL_REG.phase] = 1,
    [1] = {
        [SKILL_RULE.show] = SKILL_SHOW_LOCAL.host,
        [SKILL_RULE.zorder] = SKILL_ORDER.player_up,
        [SKILL_RULE.moment] = SKILL_REG.phase1
    }
}

---------------
-- 技能显示规则
SKILL_SHOW_RULE = {}

-- 裂地斩
SKILL_SHOW_RULE[1] = {
    beginPosX = 200,
    endPosX = 200,
    sceneX = 200
}

SKILL_SHOW_RULE[2] = {
    beginPosX = 200,
    endPosX = 200,
    sceneX = 200
}

SKILL_SHOW_PLAY = DeepCopy(SKILL_REGISTER)

SKILL_SHOW_PLAY[SKILL_RULE_ID.RULE_FOUR_PHASE][1][SKILL_RULE.nextDelay] = 0.3
SKILL_SHOW_PLAY[SKILL_RULE_ID.RULE_FOUR_PHASE][2][SKILL_RULE.nextDelay] = 0.5
SKILL_SHOW_PLAY[SKILL_RULE_ID.RULE_FOUR_PHASE][3][SKILL_RULE.nextDelay] = 0.7

SKILL_SHOW_PLAY[SKILL_RULE_ID.RULE_THREE_PHASE][1][SKILL_RULE.nextDelay] = 0
SKILL_SHOW_PLAY[SKILL_RULE_ID.RULE_THREE_PHASE][2][SKILL_RULE.nextDelay] = 0.3

SKILL_SHOW_PLAY[SKILL_RULE_ID.RULE_SKILL_3][1][SKILL_RULE.move] = 0.1
SKILL_SHOW_PLAY[SKILL_RULE_ID.RULE_SKILL_3][1][SKILL_RULE.nextDelay] = 0.3

----------------------------------技能的相关配置[远程、是否需要目标、进入的攻击状态]-----------------------------------
-- 目标类型
SKILL_TARGET_TYPE = {
    NONE = 0, -- 不需要目标
    SELF = 1, -- 目标是自己
    OTHER = 2 -- 目标是其他人
}

-- 远程/进程攻击
SKILL_DISTANCE_TYPE = {
    SHORT = 1, -- 进程攻击
    LONG = 2   -- 远程攻击
}

-- 立马释放/进入攻击状态机
SKILL_RELEASE_TYPE = {
    FAST = 1, -- 快速
    ORDER = 2 -- 等下一次状态机
}

SKILL_BASE_CONFIG = {}

-- 神盾护体
SKILL_BASE_CONFIG[SKILL_NAME_BASE_AEGIS] = {
    target = SKILL_TARGET_TYPE.SELF,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = false
}

-----------------------------------------------------------------------------------
-------------------------------------战士技能--------------------------------------
-- 普通剑术
SKILL_BASE_CONFIG[SKILL_NAME_BASE_ZS] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.ATTACK,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 刺杀剑术
SKILL_BASE_CONFIG[SKILL_NAME_CISHA_JIANSHU] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.ATTACK,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 半月弯刀
SKILL_BASE_CONFIG[SKILL_NAME_BANYUE_DAOFA] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.ATTACK,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 野蛮冲撞
SKILL_BASE_CONFIG[SKILL_NAME_YEMANNCHONGZHUANG] = {
    target = SKILL_TARGET_TYPE.NONE,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.COLLIDE,
    release = SKILL_RELEASE_TYPE.FAST,
    damage = true
}

-- 烈火剑法
SKILL_BASE_CONFIG[SKILL_NAME_LIEHUO_JIANFA] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.ATTACK,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 逐日剑法
SKILL_BASE_CONFIG[SKILL_NAME_ZHURI_JIANFA] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.ATTACK,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 开天斩
SKILL_BASE_CONFIG[SKILL_NAME_KAITIAN_ZHAN] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.ATTACK,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 十步一杀
SKILL_BASE_CONFIG[SKILL_NAME_SHIBUYISHA] = {
    target = SKILL_TARGET_TYPE.NONE,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.FAST,
    damage = true
}

-- 擒龙手
SKILL_BASE_CONFIG[SKILL_NAME_QINGLONGSHOU] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.ATTACK,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 狮子吼
SKILL_BASE_CONFIG[SKILL_NAME_SHIHOUGONG] = {
    target = SKILL_TARGET_TYPE.NONE,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.ATTACK,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 攻杀剑术
SKILL_BASE_CONFIG[SKILL_NAME_GONGSHAJIANSHU] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.ATTACK,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}
-----------------------------------------------------------------------------------
-------------------------------------法师技能--------------------------------------
-- 普通火球
SKILL_BASE_CONFIG[SKILL_NAME_BASE_FS] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 雷电术
SKILL_BASE_CONFIG[SKILL_NAME_LEIDIAN_SHU] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 地狱雷光
SKILL_BASE_CONFIG[SKILL_NAME_DIYULEIGUANG] = {
    target = SKILL_TARGET_TYPE.SELF,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 疾光电影
SKILL_BASE_CONFIG[SKILL_NAME_JIGUANGDIANYING] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 火墙
SKILL_BASE_CONFIG[SKILL_NAME_HUOQIANG] = {
    target = SKILL_TARGET_TYPE.NONE,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 冰咆哮
SKILL_BASE_CONFIG[SKILL_NAME_BINGPAOXIAO] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 寒冰掌
SKILL_BASE_CONFIG[SKILL_NAME_HANBINGZHANG] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 灭天火
SKILL_BASE_CONFIG[SKILL_NAME_MIETIANHUO] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 魔法盾
SKILL_BASE_CONFIG[SKILL_NAME_MOFADUN] = {
    target = SKILL_TARGET_TYPE.SELF,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = false
}

-- 流星火雨
SKILL_BASE_CONFIG[SKILL_NAME_LIUXINGHUOYU] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 抗拒火环
SKILL_BASE_CONFIG[SKILL_NAME_KANGJUHUOHUAN] = {
    target = SKILL_TARGET_TYPE.SELF,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 地狱火
SKILL_BASE_CONFIG[SKILL_NAME_DIYUHUO] = {
    target = SKILL_TARGET_TYPE.NONE,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 狂龙紫电
SKILL_BASE_CONFIG[SKILL_NAME_KUANGLONGZIDIAN] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 分身术
SKILL_BASE_CONFIG[SKILL_NAME_FENSHENSHU] = {
    target = SKILL_TARGET_TYPE.SELF,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = false
}

-- 爆裂火焰
SKILL_BASE_CONFIG[SKILL_NAME_BAOLIEHUOYAN] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 诱惑之光
SKILL_BASE_CONFIG[SKILL_NAME_YOUHUOZHIGUANG] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 大火球
SKILL_BASE_CONFIG[SKILL_NAME_DAHUOQIU] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 圣言术
SKILL_BASE_CONFIG[SKILL_NAME_SHENGYANSHU] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-----------------------------------------------------------------------------------
-------------------------------------道士技能--------------------------------------
-- 普通火符
SKILL_BASE_CONFIG[SKILL_NAME_BASE_DS] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 灵魂火符
SKILL_BASE_CONFIG[SKILL_NAME_LINGHUNHUOFU] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 施毒术
SKILL_BASE_CONFIG[SKILL_NAME_SHIDUSHU] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 召唤白虎
SKILL_BASE_CONFIG[SKILL_NAME_ZHAOHUAN_BAIHU] = {
    target = SKILL_TARGET_TYPE.SELF,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = false
}

-- 幽灵盾
SKILL_BASE_CONFIG[SKILL_NAME_YOULINGDUN] = {
    target = SKILL_TARGET_TYPE.SELF,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = false
}

-- 神圣战甲术
SKILL_BASE_CONFIG[SKILL_NAME_SSZJ_SHU] = {
    target = SKILL_TARGET_TYPE.SELF,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = false
}

-- 无极真气
SKILL_BASE_CONFIG[SKILL_NAME_WUJIZHENQI] = {
    target = SKILL_TARGET_TYPE.SELF,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = false
}

-- 嗜血术
SKILL_BASE_CONFIG[SKILL_NAME_SHIXUESHU] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 召唤月灵
SKILL_BASE_CONFIG[SKILL_NAME_ZHAOHUANYUELING] = {
    target = SKILL_TARGET_TYPE.SELF,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = false
}

-- 飓风破
SKILL_BASE_CONFIG[SKILL_NAME_JUFENGPO] = {
    target = SKILL_TARGET_TYPE.OTHER,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 气波功
SKILL_BASE_CONFIG[SKILL_NAME_QIBOGONG] = {
    target = SKILL_TARGET_TYPE.SELF,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = true
}

-- 群体隐身术
SKILL_BASE_CONFIG[SKILL_NAME_QUNTIYINSHENSHU] = {
    target = SKILL_TARGET_TYPE.NONE,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = false
}

-- 隐身术
SKILL_BASE_CONFIG[SKILL_NAME_YINSHENSHU] = {
    target = SKILL_TARGET_TYPE.SELF,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = false
}

-- 召唤骷髅
SKILL_BASE_CONFIG[SKILL_NAME_ZHAOHUANKULOU] = {
    target = SKILL_TARGET_TYPE.SELF,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = false
}

-- 群体治疗术
SKILL_BASE_CONFIG[SKILL_NAME_QUNTIZHILIAOSHU] = {
    target = SKILL_TARGET_TYPE.NONE,
    remote = SKILL_DISTANCE_TYPE.LONG,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = false
}

-- 治疗术
SKILL_BASE_CONFIG[SKILL_NAME_ZHILIAOSHU] = {
    target = SKILL_TARGET_TYPE.SELF,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = false
}

-- 幽灵魔甲术
SKILL_BASE_CONFIG[SKILL_NAME_YOULINGMOJIASHU] = {
    target = SKILL_TARGET_TYPE.SELF,
    remote = SKILL_DISTANCE_TYPE.SHORT,
    atkState = ALIVER_STATE.MAGIC,
    release = SKILL_RELEASE_TYPE.ORDER,
    damage = false
}
