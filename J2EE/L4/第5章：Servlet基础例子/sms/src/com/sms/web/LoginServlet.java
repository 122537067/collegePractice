package com.sms.web;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.sms.dao.UserInfoDao;
import com.sms.model.UserInfo;

@WebServlet("/login.do")
public class LoginServlet extends HttpServlet {

	private static final long serialVersionUID = 1L;
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		loginFromDatabase(request,response);
	}
	
	private void loginFromDatabase(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
		request.setCharacterEncoding("utf-8");
		response.setCharacterEncoding("utf-8");
		
		String username = request.getParameter("username");
		String pwd = request.getParameter("pwd");
		
		try
		{
			UserInfo user = new UserInfoDao(request).getUserByName(username);
			if(user==null){
				response.sendRedirect("/login.jsp?err=1");
				return;
			}
			
			if(!user.getPassword().equals(pwd)){
				response.sendRedirect("/login.jsp?err=2");
				return;
			}
			
			response.sendRedirect("/classinfo/list.jsp");
		}
		catch(Exception ex){
			throw new ServletException(ex);
		}
	}
	
	private void login(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
		request.setCharacterEncoding("utf-8");
		String username = request.getParameter("username");
		String pwd = request.getParameter("pwd");
		
		if(username.equals("admin") && pwd.equals("123456")){
			response.sendRedirect("/classinfo/list.jsp");
		}
		else{
			response.setCharacterEncoding("utf-8");
			response.sendRedirect("/login.jsp?err=1");
		}
	}

}
