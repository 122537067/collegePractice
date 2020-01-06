package UserWeb;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import model.UserInfo;
import dao.UserInfoDao;

/**
 * Servlet implementation class modify
 */
@WebServlet("/usermodify")
public class usermodify extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public usermodify() {
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
		if(!PermissionHelper.validPermission(request, response,"UserModif")) return;
		request.setCharacterEncoding("utf-8");
		String id = request.getParameter("id");
		
		UserInfoDao dao = new UserInfoDao();
		try {
			UserInfo cInfo = dao.get(Long.parseLong(id));//id转型
			request.setAttribute("getInfo", cInfo);
		} catch (Exception e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
		request.getRequestDispatcher("user_jsp/modify.jsp").forward(request,response);
	}

}
