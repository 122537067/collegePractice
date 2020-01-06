package ClassWeb;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import UserWeb.PermissionHelper;
import model.ClassInfo;
import dao.ClassInfoDao;

/**
 * Servlet implementation class modify
 */
@WebServlet("/classmodify")
public class classmodify extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public classmodify() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doPost(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		if(!PermissionHelper.validPermission(request, response,"ClassModif")) return;
		request.setCharacterEncoding("utf-8");
		String id = request.getParameter("classid");
		ClassInfoDao dao = new ClassInfoDao();
		try {
			ClassInfo cInfo = dao.get(Long.parseLong(id));//id转型
			request.setAttribute("mo_classInfo", cInfo);
		} catch (Exception e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
		request.getRequestDispatcher("class_jsp/modify.jsp").forward(request,response);
	}

}
