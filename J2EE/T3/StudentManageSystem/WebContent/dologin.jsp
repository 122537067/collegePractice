<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%
	request.setCharacterEncoding("utf-8");
	String username = request.getParameter("username");
	String pwd = request.getParameter("pwd");

 	if(username.equals("admin") && pwd.equals("123456")){
		response.sendRedirect("/StudentManageSystem/classinfo/list.jsp");
	}
	else{
		response.setCharacterEncoding("utf-8");
		response.sendRedirect("/StudentManageSystem/login.jsp?error_message=1");
	}
%>