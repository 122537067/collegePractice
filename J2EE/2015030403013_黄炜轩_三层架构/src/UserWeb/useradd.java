package UserWeb;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import model.UserInfo;
import service.UserFunctionService;

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
		if(!PermissionHelper.validPermission(request, response,"UserAdd")) return;
		
		request.setCharacterEncoding("utf-8");
		String submit = request.getParameter("addsubmit");
		if(submit==null) return;
		
		String name = request.getParameter("addname");
		String pass = request.getParameter("addpass");
		
		new UserFunctionService().Useradd(name, pass);
		try {
			List<UserInfo> getlist = new UserFunctionService().Setlist();
			request.setAttribute("setlist", getlist);
			} 
		catch (Exception e) {
			e.printStackTrace();
		}	
		request.getRequestDispatcher("user_jsp/list.jsp").forward(request,response);
		
	}

}
