package com.zhengjiaxin.web;


import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.zhengjiaxin.model.UserInfo;

/**
 * 首页，登录用户可以访问
 * @author hp
 *
 */
@WebServlet("/index.do")
public class IndexServlet extends HttpServlet {

	private static final long serialVersionUID = 1L;

	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setCharacterEncoding("utf-8");

		UserInfo user = (UserInfo)request.getSession().getAttribute("user");
		
		if(user==null){
			response.sendRedirect("/login.html");
			return;
		}
		
		response.sendRedirect("/views/index.jsp");
	}


}
