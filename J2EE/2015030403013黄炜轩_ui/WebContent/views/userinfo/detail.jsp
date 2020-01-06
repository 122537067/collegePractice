<%@ page language="java" contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<!DOCTYPE html>

<html>
<head>
    <title>用户信息</title>
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
    	<a href="javascript:void(0)" class="easyui-linkbutton" id="btnReturn" icon="icon-return" onclick="closeWindow()">返回</a>
    </div>
</div>

<div data-options="region:'center',border:true,fit:false">
    <form id="EditForm" method="post" enctype="multipart/form-data">
        <table>
        	<tr>
        		<td>用户名</td>
        		<td><input id="Username" name="Username" value="${user.username}" readonly required='true' class="easyui-textbox"></td>
        	</tr>
			<tr>
        		<td>密码</td>
        		<td><input id="Password" name="Password" value="${user.password}" readonly required='true' class="easyui-textbox"></td>
        	</tr>
        </table>
    </form>
    <div style="height:20px;"></div>
</div>

</body>
</html>