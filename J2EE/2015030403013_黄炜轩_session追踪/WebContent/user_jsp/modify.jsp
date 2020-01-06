<%@page import="java.util.ArrayList"%>
<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="UserInfo.UserInfo" %>
<%@ page import="UserInfo.UserInfoDao"%>

<!DOCTYPE html>
<html>
<%
	String path = request.getContextPath();
	String basePath = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort()
			+ path + "/";
%>
<head>
<base href="<%=basePath%>">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>修改用户信息</title>
</head>
<%--
	request.setCharacterEncoding("utf-8");
	String id = request.getParameter("id");
	ClassInfoDao dao = new ClassInfoDao(request);
	ClassInfo cInfo = dao.get(Long.parseLong(id));
--%>
<%
	//List<ClassInfo> list=(List)request.getAttribute("getInfo");
	UserInfo cInfo=(UserInfo)request.getAttribute("getInfo");
%>
<body>
	<h2 align="center">修改用户信息</h2>
	<hr/>
	<div style="margin:10px;">
		<form method="post" action="userdomodify">
			<input type="hidden" name="id" value="<%=cInfo.getId()%>" >
			用户名称：<input type="text" name="name" value="<%=cInfo.getUsername() %>">
			用户密码：<input type="text" name="pass" value="<%=cInfo.getPassword() %>">
			<input type="submit" name="submit" value="确定">
		</form>
	</div>
</body>
</html>
