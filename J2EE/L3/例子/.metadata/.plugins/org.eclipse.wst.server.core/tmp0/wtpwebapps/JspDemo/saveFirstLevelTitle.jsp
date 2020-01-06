<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="com.demo.FirstLevelTitle" %>
<%@ page import="com.demo.FirstLevelTitleDao" %>
<%@ page import="java.util.Date" %>
<%
	request.setCharacterEncoding("utf-8");
	String titlename = request.getParameter("titlename");
	FirstLevelTitle model = new FirstLevelTitle();
	model.setTitleName(titlename);
	model.setCreator("管理员");
	model.setCreateTime(new Date());
	
	FirstLevelTitleDao dao = new FirstLevelTitleDao(request);
	try
	{
		dao.add(model);
		//request.getRequestDispatcher("success.jsp").forward(request, response);
		response.sendRedirect("success.jsp");
	}
	catch(Exception ex){
		ex.printStackTrace();
		//request.getRequestDispatcher("error.jsp").forward(request, response);
		response.sendRedirect("error.jsp");
	}
	
%>