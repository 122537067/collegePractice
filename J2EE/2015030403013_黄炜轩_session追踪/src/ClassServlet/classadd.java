package ClassServlet;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import ClassInfo.ClassInfo;
import ClassInfo.ClassInfoDao;
import UserServlet.PermissionHelper;

/**
 * Servlet implementation class add
 */
@WebServlet("/classadd")
public class classadd extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public classadd() {
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
		
		if(!PermissionHelper.validPermission(request, response,"ClassAdd")) return;
		request.setCharacterEncoding("utf-8");
		String submit = request.getParameter("submit");
		if(submit==null) return;
		
		String name = request.getParameter("classname");
		ClassInfoDao dao = new ClassInfoDao(request);
		ClassInfo Info = new ClassInfo();
		Info.setName(name);
		try {
			dao.add(Info);
		} catch (Exception e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
		
		
		List<ClassInfo> setlist;
		try {
			setlist = new ClassInfoDao(request).query(null);
			request.setAttribute("setlist", setlist);
			} 
		catch (Exception e) {
			e.printStackTrace();
		}	
		request.getRequestDispatcher("class_jsp/list.jsp").forward(request,response);
		
	}

}
