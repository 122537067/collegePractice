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
 * 获取查看用户页面，这里构建用户数据
 * @author hp
 *
 */
@WebServlet("/userinfo/getdetail.do")
public class GetUserInfoDetailServlet extends HttpServlet {

	private static final long serialVersionUID = 1L;

	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setCharacterEncoding("utf-8");
		
		long id = Long.parseLong(request.getParameter("id"));

		UserInfo user = new UserInfoService().getUserInfoByID(id);
		
		request.setAttribute("user", user);
		
		request.getRequestDispatcher("/views/userinfo/detail.jsp").forward(request, response);
	}


}
