<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>欢迎注册</title>
</head>
<body>
<%
	request.setCharacterEncoding("utf-8");
	String username = request.getParameter("username");
	String pwd = request.getParameter("pwd");
	String[] channels = request.getParameterValues("channel");
	
%>
<h2>欢迎您的注册：</h2>
<p>用户名：<%= username%></p>
<p>密码：<%= pwd%></p>
<p>获悉渠道：
<%
	for(String c:channels){
		out.print(c+" ");
	}
%>
</p>
</body>
</html>