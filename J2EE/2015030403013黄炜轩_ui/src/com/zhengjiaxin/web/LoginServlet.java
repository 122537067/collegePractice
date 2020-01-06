package com.zhengjiaxin.web;


import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.zhengjiaxin.model.UserInfo;
import com.zhengjiaxin.service.UserInfoService;

/**
 * 处理登录
 * @author hp
 *
 */
@WebServlet("/login.do")
public class LoginServlet extends HttpServlet {

	private static final long serialVersionUID = 1L;

	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setCharacterEncoding("utf-8");
		
		String username = request.getParameter("username");
		String pwd = request.getParameter("pwd");
		
		String msg = "";
		
		UserInfo user = new UserInfoService().login(username, pwd);
		
		if(user!=null){
			request.getSession().setAttribute("user", user);
			msg = "success";
		}
		else{
			msg = "用户名或者密码错误";
		}
		
		response.getWriter().print(msg);
	}


}
