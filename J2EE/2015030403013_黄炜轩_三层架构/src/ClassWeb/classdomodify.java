package ClassWeb;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import UserWeb.PermissionHelper;
import model.ClassInfo;
import service.ClassFunctionService;
import dao.ClassInfoDao;

/**
 * Servlet implementation class domodify
 */
@WebServlet("/classdomodify")
public class classdomodify extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public classdomodify() {
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
		String id = request.getParameter("classid");
		String name = request.getParameter("classname");
		
		new ClassFunctionService().Classdomodify(id, name);
		
		//返回list
		List<ClassInfo> setlist;
		try {
			setlist = new ClassInfoDao().query(null);
			request.setAttribute("setlist", setlist);
			} 
		catch (Exception e) {
			e.printStackTrace();
		}	
		request.getRequestDispatcher("class_jsp/list.jsp").forward(request,response);
	}

}
