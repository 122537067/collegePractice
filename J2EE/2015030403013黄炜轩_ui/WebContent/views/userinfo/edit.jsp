<%@ page language="java" contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<!DOCTYPE html>

<html>
<head>
    <title>编辑用户资料</title>
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
    <style type="text/css">
        input, select {
            width: 200px;
        }
        td {
            padding: 2px 2px 2px 10px;
        }
    </style>
</head>
<body class="easyui-layout">

<div data-options="region:'north',border:true,title:''" >
    <div style="padding:2px;float:left;height:25px;">
    	<a href="javascript:void(0)" id="btnSave" class="easyui-linkbutton" iconCls="icon-save"  onclick="submitForm()">保存</a>
        <a href="javascript:void(0)" class="easyui-linkbutton" id="btnReturn" icon="icon-return" onclick="closeWindow()">返回</a>
    </div>
</div>

<div data-options="region:'center',border:true,fit:false">
    <form id="EditForm" method="post" action="/userinfo/edituser.do">
    	<input type="hidden" name="Id" value="${user.id}">
        <table>
        	<tr>
        		<td>用户名</td>
        		<td><input id="Username" name="Username" value="${user.username}" required='true' class="easyui-textbox"></td>
        	</tr>
			<tr>
        		<td>密码</td>
        		<td><input id="Password" name="Password" value="${user.password}" required='true' class="easyui-textbox"></td>
        	</tr>
        </table>
    </form>
    <div style="height:20px;"></div>
</div>

<script>

    $(function () {
        $('#EditForm').form({
            onSubmit: function () {                
                var r = $("#EditForm").form('validate');
                if(r)
                {
                    $.messager.progress({
                        title: '正在更新',
                        msg: '请稍后...'
                    });
                    return true;
                }
                else {
                    return false;
                }
            },
            success: function (data) {
                $.messager.progress('close');
                data = eval('(' + data + ')');
                if (data.success) {
                	window.top.showInfo(data.message);
                    saveData();
                }
                else {
                    window.top.showError(data.message);
                }
            }
        });

    });

    function saveData()
    {
        returnReload();
        closeWindow();
    }

    function submitForm() {
        $('#EditForm').form('submit');
    }

</script>

</body>
</html>