<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>


<!DOCTYPE html>
<html>
<%
	String path = request.getContextPath();
	String basePath = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort()
			+ path + "/";
%>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>添加用户</title>
</head>
<base href="<%=basePath%>">
<body>
	<h2 align="center">添加用户</h2>
	<hr/>
	<div style="margin:10px;">
		<form method="post" action="useradd">
			用户名称：<input type="text" name="addname">
			用户密码：<input type="text" name="addpass">
			<input type="submit" name="addsubmit" value="确定">
		</form>
	</div>
</body>
</html>
