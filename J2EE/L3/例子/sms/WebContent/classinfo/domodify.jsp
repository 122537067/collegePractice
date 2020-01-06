<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="com.sms.model.ClassInfo" %>
<%@ page import="com.sms.dao.ClassInfoDao"%>
<%
	request.setCharacterEncoding("utf-8");
	String id = request.getParameter("id");
	String name = request.getParameter("name");
	ClassInfoDao dao = new ClassInfoDao(request);
	ClassInfo c = new ClassInfo();
	c.setId(Long.parseLong(id));
	c.setName(name);
	dao.update(c);
	response.sendRedirect("/classinfo/list.jsp");
%>