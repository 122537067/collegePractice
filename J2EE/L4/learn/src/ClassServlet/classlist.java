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
 * Servlet implementation class list
 */
@WebServlet("/classlist")
public class classlist extends HttpServlet {
	private static final long serialVersionUID = 1L;
	public classlist() {
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
		response.setCharacterEncoding("utf-8");
		String name = request.getParameter("classname");
		List<ClassInfo> setlist;
			try {
				setlist = new ClassInfoDao(request).query(name);
				request.setAttribute("setlist", setlist);
			} catch (Exception e) {
				e.printStackTrace();
		}		
		request.getRequestDispatcher("class_jsp/list.jsp").forward(request, response);
	}

}
