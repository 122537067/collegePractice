<%@ page language="java" contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<!DOCTYPE html>

<html>
<head>
    <title>学员管理系统</title>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    
	<link href="/resources/jquery-easyui-1.5.2/themes/default/easyui.css" rel="stylesheet">
    <link href="/resources/jquery-easyui-1.5.2/themes/icon.css" rel="stylesheet">
    
    <link href="/resources/themes/icons.css" rel="stylesheet">
	<link href="/resources/themes/site.css" rel="stylesheet">

    <script src="/resources/jquery-easyui-1.5.2/jquery.min.js"></script>
    <script src="/resources/jquery-easyui-1.5.2/jquery.easyui.min.js"></script>
	<script src="/resources/jquery-easyui-1.5.2/locale/easyui-lang-zh_CN.js"></script>
	

	<script src="/resources/sms/msgbox.js"></script>
	<script src="/resources/sms/date.js"></script>
	<script src="/resources/sms/data.js"></script>
    <style>
        .title
        {
            padding:15px 0 0 50px;
            FONT-WEIGHT: bolder; 
            FONT-SIZE: 28px;
            color:#1b76b5;
            letter-spacing:5px;
        }
    </style>
</head>
<body class="easyui-layout">

    <div data-options="region:'north',border:false,title:''" style="height:65px;padding:0px;overflow:hidden;">
        <div style="clear:both;overflow:hidden;background:url(/resources/themes/images/Top_bg.gif)">
            <div style="float:left;width:165px;">
                <img alt="" style="margin:6px 0 0 0;" src="/resources/themes/images/logo.png" width="139" height="55" />
            </div>
            <div style="float:left;" class="title">学员管理系统</div>          
            <div style="float:right;padding:5px 60px 5px 0px;">
                <a href="#" id="btnModifyPwd" class="easyui-linkbutton" data-options="iconCls:'icon-large-password',size:'large',iconAlign:'top'">修改密码</a>
                <a href="#" id="btnLoginout" class="easyui-linkbutton" data-options="iconCls:'icon-large-exit',size:'large',iconAlign:'top'">重新登陆</a>
            </div>
        </div>
    </div>

    <div data-options="region:'west',split:true,title:'欢迎您,${user.username}'" style="width:200px;height:100%;overflow: auto">
        <div class="easyui-layout" data-options="fit:true">
            <div region="center" border="false">
            	<div id="systemMenus" class="easyui-accordion" data-options="fit:false,border:false,animate:false">
					<div title="系统管理" data-options="iconCls:'icon-xtgl'" style="padding-left:10px;">
						<a href="javascript:void(0)" onclick="addTab('用户管理','/views/userinfo/list.html','icon-menu')" class="easyui-linkbutton" data-options="iconCls:'icon-menu',plain:true">用户管理</a><br>
					</div>
					<div title="学员管理" data-options="iconCls:'icon-zzjg'" style="padding-left:10px;">
						<a href="javascript:void(0)" onclick="addTab('班级管理','/views/klass/list.html','icon-menu')" class="easyui-linkbutton" data-options="iconCls:'icon-menu',plain:true">班级管理</a><br>
						<a href="javascript:void(0)" onclick="addTab('学员管理','/views/klass/list.html','icon-menu')" class="easyui-linkbutton" data-options="iconCls:'icon-menu',plain:true">学员管理</a><br>
					</div>
				</div>
            </div>
        </div>
    </div>

    <div data-options="region:'center',border:false" style="overflow:hidden;">
        <div id="mainTab" style="overflow:hidden;">
        </div>
    </div>
    <div id="centerMenu">
        <a href="javascript:void(0)" class="easyui-linkbutton" data-options="plain:true,iconCls:'icon-expand'" onclick="full();" title="全屏窗口"></a>
        <a href="javascript:void(0)" class="easyui-linkbutton" data-options="plain:true,iconCls:'icon-collapse'" onclick="unFull();" title="正常窗口"></a>
    </div>

    <!--修改密码窗口-->
    <div id="winModifyPwd" class="easyui-window" title="修改密码" collapsible="false" minimizable="false"
         maximizable="false" icon="icon-save" style="width: 320px; height: 180px; padding: 5px;
        background: #fafafa;" closed=true>
        <div class="easyui-layout" fit="true">
            <div region="center" border="false" style="padding: 10px; background: #fff; border: 1px solid #ccc;">
                <table cellpadding="3">
                    <tr>
                        <td>新密码：</td>
                        <td><input class="easyui-textbox" id="txtNewPass" type="Password" /></td>
                    </tr>
                    <tr>
                        <td>确认密码：</td>
                        <td><input class="easyui-textbox" id="txtRePass" type="Password" /></td>
                    </tr>
                </table>
            </div>
            <div region="south" border="false" style="text-align: right; height: 30px; line-height: 30px; overflow:hidden;">
                <a id="btnEp" class="easyui-linkbutton" icon="icon-ok" href="javascript:void(0)" style="height:30px">确定</a>
                <a id="btnCancel" class="easyui-linkbutton" icon="icon-cancel" href="javascript:void(0)" style="height:30px">取消</a>
            </div>
        </div>
    </div>

    <div id="tab_menu" class="easyui-menu" style="width: 150px;">
        <div id="tab_menu-tabrefresh" data-options="iconCls:'icon-reload'">刷新</div>
        <div id="tab_menu-openFrame"> 在新的窗体打开</div>
        <div class="menu-sep"> </div>
        <div id="tab_menu-tabcloseall">关闭所有</div>
        <div id="tab_menu-tabcloseother">关闭其他标签页</div>
        <div id="tab_menu-tabcloseright">关闭右边</div>
        <div id="tab_menu-tabcloseleft">关闭左边</div>
        <div id="tab_menu-tabclose" data-options="iconCls:'icon-remove'">关闭</div>
        <div id="menu" class="easyui-menu" style="width: 150px;">
        </div>
    </div>

<script type="text/javascript">

    $(function(){
        $("#systemMenus").accordion('getSelected').panel('collapse')
    });

    function addTab(subtitle, url, icon) {
        if (!$("#mainTab").tabs('exists', subtitle)) {
            $("#mainTab").tabs('add', {
                title: subtitle,
                closable: true,
                closed: true,
                icon: icon
            });

            var pp = $('#mainTab').tabs('getSelected');
            pp.panel({
                content: createFrame(url)
            });

        } else {
            $("#mainTab").tabs('select', subtitle);
        }

        bindTab();
    }

    function createFrame(url) {
        var s = '<iframe frameborder="0" src="' + url + '" scrolling="auto" style="width:100%; height:98%"></iframe>';
        return s;
    }

    function openAtNewWindow() {
        var url = $(".tabs-panels .panel").eq($('.tabs-selected').index()).find("iframe").attr("src");
        window.open(url);
    }

    function bindTab() {

        $(".tabs-inner").unbind();

        /*双击在新窗口打开该标签*/
        $(".tabs-inner").dblclick(function () {
            openAtNewWindow();
        })

        /*为选项卡绑定右键*/
        $(".tabs-inner").bind('contextmenu', function (e) {
            $('#tab_menu').menu('show', {
                left: e.pageX,
                top: e.pageY
            });

            var subtitle = $(this).children(".tabs-closable").text();

            $('#tab_menu').data("currtab", subtitle);
            $('#tabs').tabs('select', subtitle);

            return false;
        });
    }

    // 关闭当前
    function closeCurrentTab() {
        var currtab_title = $('.tabs-selected .tabs-inner span').text();

        $('#mainTab').tabs('close', currtab_title);
    }

    /* 标签菜单操作 */
    $(function () {
        /*双击在新窗口打开该标签*/
        $(".tabs-inner").dblclick(function () {
            openAtNewWindow();
        })

        $('#tab_menu-tabrefresh').click(function () {
            /*重新设置该标签 */
            var url = $(".tabs-panels .panel").eq($('.tabs-selected').index()).find("iframe").attr("src");
            $(".tabs-panels .panel").eq($('.tabs-selected').index()).find("iframe").attr("src", url);
        });

        //在新窗口打开该标签
        $('#tab_menu-openFrame').click(function () {
            openAtNewWindow();
        });

        //关闭当前
        $('#tab_menu-tabclose').click(function () {
            var currtab_title = $('.tabs-selected .tabs-inner span').text();

            if (currtab_title == "我的桌面") {
                return false;
            }

            $('#mainTab').tabs('close', currtab_title);

        });

        //全部关闭
        $('#tab_menu-tabcloseall').click(function () {
            $('.tabs-inner span').each(function (i, n) {
                if ($(this).parent().next().is('.tabs-close')) {
                    var t = $(n).text();
                    $('#mainTab').tabs('close', t);
                }
            });
        });

        //关闭除当前之外的TAB
        $('#tab_menu-tabcloseother').click(function () {
            var currtab_title = $('.tabs-selected .tabs-inner span').text();
            $('.tabs-inner span').each(function (i, n) {
                if ($(this).parent().next().is('.tabs-close')) {
                    var t = $(n).text();
                    if (t != currtab_title)
                        $('#mainTab').tabs('close', t);
                }
            });
        });

        //关闭当前右侧的TAB
        $('#tab_menu-tabcloseright').click(function () {
            var nextall = $('.tabs-selected').nextAll();
            if (nextall.length == 0) {
                return false;
            }

            nextall.each(function (i, n) {
                if ($('a.tabs-close', $(n)).length > 0) {
                    var t = $('a:eq(0) span', $(n)).text();
                    $('#mainTab').tabs('close', t);
                }
            });

            return false;
        });

        //关闭当前左侧的TAB
        $('#tab_menu-tabcloseleft').click(function () {

            var prevall = $('.tabs-selected').prevAll();
            if (prevall.length == 0) {
                return false;
            }

            prevall.each(function (i, n) {
                if ($('a.tabs-close', $(n)).length > 0) {
                    var t = $('a:eq(0) span', $(n)).text();
                    $('#mainTab').tabs('close', t);
                }
            });

            return false;
        });
    });

    // 退出登陆操作
    $(function () {
        $("#btnLoginout").bind('click', function () {
            $.messager.confirm('系统提示', '您确定要退出本次登录吗?', function (r) {
                if (r) {
                    location.href = '/logout.do';
                }
            });
        });
    });

    /** 修改密码操作 **/

    function saveNewPassword() {

        var valueNewPwd = $("#txtNewPass").textbox("options").value;
        var valueRePwd = $("#txtRePass").textbox("options").value;

        if (valueNewPwd == '') {
            $.messager.alert("温馨提示", "请输入密码！", "info");
            return false;
        }
        if (valueRePwd == '') {
            $.messager.alert("温馨提示", "请再一次输入密码", "info");
            return false;
        }

        if (valueNewPwd != valueRePwd) {
            $.messager.alert('温馨提示', '两次密码不一至！请重新输入', 'info');
            return false;
        }

        $.post('/updatePassword.do', { "newPassword": valueNewPwd },
             function (msg) {
                 $.messager.alert('温馨提示', msg, 'info');
                 $('#winModifyPwd').window('close');
             });
    }

    function initTabs() {
        $('#mainTab').tabs({
            border: true,
            fit: true,
            tools: '#centerMenu'
        });
    }

    $(function () {
        initTabs();

        $('#btnModifyPwd').bind('click', function () {
            $('#winModifyPwd').window('open');
        });

        $('#btnEp').click(function () {
            saveNewPassword();
        });

        $('#btnCancel').click(function () {
            $('#winModifyPwd').window('close');
        });

        $('#winModifyPwd').window({
            onBeforeClose: function () {
                $('#txtNewPass').textbox('clear');
                $('#txtRePass').textbox('clear');
            }
        });
        

    });

    $.extend($.fn.layout.methods, {
        full: function (jq) {
            return jq.each(function () {
                var layout = $(this);
                var center = layout.layout('panel', 'center');
                center.panel('maximize');
                center.parent().css('z-index', 10);

                $(window).on('resize.full', function () {
                    layout.layout('unFull').layout('resize');
                });
            });
        },
        unFull: function (jq) {
            return jq.each(function () {
                var center = $(this).layout('panel', 'center');
                center.parent().css('z-index', 'inherit');
                center.panel('restore');
                $(window).off('resize.full');
            });
        }
    });
    function full() {
        $("body").layout("full");
    }
    function unFull() {
        $("body").layout("unFull");
    }

    function getWindowFromCurrentTab()
    {
        var tab = window.parent.$('#mainTab').tabs('getSelected');

        var iframes = tab.find('iframe');
        return iframes[0].contentWindow;
    }

    function getCurrentTabTitle()
    {
        var currtab_title = $('.tabs-selected .tabs-inner span').text();
        return currtab_title;
    }

    function getWindowByTabTitle(title)
    {
        var tab = $('#mainTab').tabs('getTab',title);

        var iframes = tab.find('iframe');
        return iframes[0].contentWindow;
    }

</script>

</body>
</html>
