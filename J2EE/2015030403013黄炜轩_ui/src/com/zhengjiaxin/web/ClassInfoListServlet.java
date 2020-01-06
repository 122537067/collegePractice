package com.zhengjiaxin.web;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.zhengjiaxin.service.ClassInfoService;

/**
 * 班级信息列表数据
 * @author hp
 *
 */
@WebServlet("/classinfo/list.do")
public class ClassInfoListServlet extends HttpServlet{

	private static final long serialVersionUID = 1L;

	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setCharacterEncoding("utf-8");
		
		try{
			String classes = new ClassInfoService().getClassInfoJsonData();
			response.getWriter().print(classes);
		}
		catch(Exception ex){
			ex.printStackTrace();
			response.getWriter().print(ex.getMessage());
		}
	}

}
