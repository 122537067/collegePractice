package UserServlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import UserInfo.UserInfo;
import UserInfo.UserInfoDao;

/**
 * Servlet implementation class userlogin
 */
@WebServlet("/userlogin")
public class userlogin extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public userlogin() {
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
		
		request.setCharacterEncoding("utf-8");
		response.setCharacterEncoding("utf-8");
		
		String username = request.getParameter("username");
		String pwd = request.getParameter("pwd");
		
		try
		{
			UserInfoDao userDao = new UserInfoDao(request);
			UserInfo user = new UserInfoDao(request).getUserByName(username);
			if(user==null){
				response.sendRedirect("/login.jsp?err=1");
				return;
			}
			
			if(!user.getPassword().equals(pwd)){
				response.sendRedirect("/login.jsp?err=2");
				return;
			}
			
			user.setRoles(userDao.loadPermissions(user.getId()));
			
			request.getSession().setAttribute(PermissionHelper.user_session_key, user);
			
			response.sendRedirect("index.jsp");
		}
		catch(Exception ex){
			throw new ServletException(ex);
		}
	}

}
