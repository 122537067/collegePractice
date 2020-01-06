<%@page import="java.util.List"%>
<%@page import="com.sun.org.apache.bcel.internal.generic.NEW"%>
<%@page import="org.apache.jasper.tagplugins.jstl.core.ForEach"%>
<%@page import="java.util.ArrayList"%>
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="UserInfo.UserInfo" %>
<%@ page import="UserInfo.UserInfoDao" %>
<%@ page import="UserServlet.userlist"%>
<!DOCTYPE html>
<html>
<%
	String path = request.getContextPath();
	String basePath = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort()
			+ path + "/";  
    List<UserInfo> list = (List)request.getAttribute("setlist");
%> 
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
</head>
<base href="<%=basePath%>">
<body>
	<h2 align="center">用户信息管理</h2>
	<hr/>
	<div style="margin:10px;">
		<form method="post" action="userlist">
			用户名称：<input type="text" name="name">
			<input type="submit" value="查询">
		</form>
	</div>
	<a href="user_jsp/add.jsp">添加用户</a>
	<table border="1">
		<tr>
			<th>id</th>
			<th>name</th>
			<th>password</th>
			<th>操作</th>
		</tr>
		<%  if(list!=null){
				for(int i=0;i<list.size();i++){
					UserInfo Info=(UserInfo)list.get(i);
			%>
			<tr>
				<td><%=Info.getId() %></td>
				<td><%=Info.getUsername() %></td>
				<td><%=Info.getPassword() %></td>
				<td>
				<a href="usermodify?id=<%=Info.getId() %>">修改</a>
				<a href="userdelete?id=<%=Info.getId() %>">删除</a>
				</td>
			</tr>
			<%}
		}
			else{%>
			<h1>DB没数据！！</h1>
			<%
			}
			%>
	</table>
</body>
</html>