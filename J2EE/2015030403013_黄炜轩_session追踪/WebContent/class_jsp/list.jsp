<%@page import="java.util.List"%>
<%@page import="com.sun.org.apache.bcel.internal.generic.NEW"%>
<%@page import="org.apache.jasper.tagplugins.jstl.core.ForEach"%>
<%@page import="java.util.ArrayList"%>
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="ClassInfo.ClassInfo"%>
<%@ page import="ClassInfo.ClassInfoDao"%>
<%@ page import="ClassServlet.classlist"%>
<!DOCTYPE html>
<html>
<%
	String path = request.getContextPath();
	String basePath = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort()
			+ path + "/";  
    List<ClassInfo> list = (List)request.getAttribute("setlist");
%> 
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
</head>
<base href="<%=basePath%>">
<body>
	<h2 align="center">班级信息管理</h2>
	<hr/>
	<div style="margin:10px;">
		<form method="post" action="classlist">
			班级名称：<input type="text" name="classname">
			<input type="submit" value="查询">
		</form>
	</div>
	<a href="class_jsp/add.jsp">添加班级</a>
	<table border="1">
		<tr>
			<th>班级编号</th>
			<th>班级名称</th>
			<th>操作</th>
		</tr>
		<%  if(list!=null){
				for(int i=0;i<list.size();i++){
					ClassInfo Info=(ClassInfo)list.get(i);
			%>
			<tr>
				<td><%=Info.getId() %></td>
				<td><%=Info.getName() %></td>
				<td>
				<a href="classmodify?classid=<%=Info.getId() %>">修改</a>
				<a href="classdelete?classid=<%=Info.getId() %>">删除</a>
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