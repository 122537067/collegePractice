package UserServlet;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import UserInfo.UserInfo;
import UserInfo.UserInfoDao;
/**
 * Servlet implementation class list
 */
@WebServlet("/userlist")
public class userlist extends HttpServlet {
	private static final long serialVersionUID = 1L;
	public userlist() {
		super();
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
		if(!PermissionHelper.validPermission(request, response,"UserList")) return;
		response.setCharacterEncoding("utf-8");
		String name = request.getParameter("name");
		List<UserInfo> setlist;
			try {
				setlist = new UserInfoDao(request).query(name);
				request.setAttribute("setlist", setlist);
			} catch (Exception e) {
				e.printStackTrace();
		}		
		request.getRequestDispatcher("user_jsp/list.jsp").forward(request, response);
	}

}
