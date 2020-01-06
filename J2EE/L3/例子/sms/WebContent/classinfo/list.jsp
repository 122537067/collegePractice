<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.util.List" %>
<%@ page import="com.sms.model.ClassInfo" %>
<%@ page import="com.sms.dao.ClassInfoDao"%>

<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>班级信息管理</title>
</head>
<%
	request.setCharacterEncoding("utf-8");
	String name = request.getParameter("name");
	List<ClassInfo> list = new ClassInfoDao(request).query(name);
%>
<body>
	<h2 align="center">班级信息管理</h2>
	<hr/>
	<div style="margin:10px;">
		<form method="post" action="list.jsp">
			班级名称：<input type="text" name="name">
			<input type="submit" value="查询">
		</form>
	</div>
	<a href="/classinfo/add.jsp">添加班级</a>
	<table border="1" width="50%">
		<tr>
			<th>班级编号</th>
			<th>班级名称</th>
			<th>操作</th>
		</tr>
		<%
		for(ClassInfo c:list){
		%>
			<tr>
				<td><%=c.getId() %></td>
				<td><%=c.getName() %></td>
				<td>
				<a href="/classinfo/modify.jsp?id=<%=c.getId() %>">修改</a>
				<a href="/classinfo/delete.jsp?id=<%=c.getId() %>">删除</a>
				</td>
			</tr>
		<%
		}
		%>
	</table>
</body>
</html>