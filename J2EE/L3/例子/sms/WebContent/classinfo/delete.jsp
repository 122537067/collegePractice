<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="com.sms.model.ClassInfo" %>
<%@ page import="com.sms.dao.ClassInfoDao"%>
<%
	request.setCharacterEncoding("utf-8");
	String id = request.getParameter("id");
	ClassInfoDao dao = new ClassInfoDao(request);
	dao.delete(Long.parseLong(id));
	response.sendRedirect("/classinfo/list.jsp");
%>