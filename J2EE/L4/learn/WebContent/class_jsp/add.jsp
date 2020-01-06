<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="ClassInfo.ClassInfo" %>
<%@ page import="ClassInfo.ClassInfoDao"%>

<!DOCTYPE html>
<html>
<%
	String path = request.getContextPath();
	String basePath = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort()
			+ path + "/";
%>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>添加班级</title>
</head>
<base href="<%=basePath%>">
<body>
	<h2 align="center">添加班级信息</h2>
	<hr/>
	<div style="margin:10px;">
		<form method="post" action="classadd">
			班级名称：<input type="text" name="classname">
			<input type="submit" name="submit" value="确定">
		</form>
	</div>
</body>
</html>
