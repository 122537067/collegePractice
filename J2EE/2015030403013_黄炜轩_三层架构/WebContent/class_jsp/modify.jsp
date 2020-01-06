<%@page import="java.util.ArrayList"%>
<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="model.ClassInfo" %>
<%@ page import="dao.ClassInfoDao"%>

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
<title>修改信息</title>
</head>
<%--
	request.setCharacterEncoding("utf-8");
	String id = request.getParameter("id");
	ClassInfoDao dao = new ClassInfoDao(request);
	ClassInfo cInfo = dao.get(Long.parseLong(id));
--%>
<%
	//List<ClassInfo> list=(List)request.getAttribute("getInfo");
	ClassInfo cInfo=(ClassInfo)request.getAttribute("mo_classInfo");
%>
<body>
	<h2 align="center">修改班级信息</h2>
	<hr/>
	<div style="margin:10px;">
		<form method="post" action="classdomodify">
			<input type="hidden" name="classid" value="<%=cInfo.getId()%>" >
			班级名称：<input type="text" name="classname" value="<%=cInfo.getName()%>">
			<input type="submit" name="submit" value="确定">
		</form>
	</div>
</body>
</html>
