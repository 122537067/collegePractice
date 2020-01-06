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
 * Servlet implementation class add
 */
@WebServlet("/useradd")
public class useradd extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public useradd() {
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
		String submit = request.getParameter("addsubmit");
		if(submit==null) return;
		
		String name = request.getParameter("addname");
		String pass = request.getParameter("addpass");
		UserInfoDao dao = new UserInfoDao(request);
		UserInfo Info = new UserInfo();
		Info.setUsername(name);
		Info.setPassword(pass);
		try {
			dao.add(Info);
		} catch (Exception e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
			
		List<UserInfo> setlist;
		try {
			setlist = new UserInfoDao(request).query(null);
			request.setAttribute("setlist", setlist);
			} 
		catch (Exception e) {
			e.printStackTrace();
		}	
		request.getRequestDispatcher("user_jsp/list.jsp").forward(request,response);
		
	}

}
