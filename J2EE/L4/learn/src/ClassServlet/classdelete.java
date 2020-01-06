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

/**
 * Servlet implementation class delete
 */
@WebServlet("/classdelete")
public class classdelete extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public classdelete() {
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
		String id = request.getParameter("classid");
		ClassInfoDao dao = new ClassInfoDao(request);
		try {
			dao.delete(Long.parseLong(id));
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
