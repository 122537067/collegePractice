package com.mysms.web;

import com.mysms.iservice.IUserInfoService;
import com.mysms.model.UserInfo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@Controller
@RequestMapping("/userinfo")
public class UserInfoController extends BaseController{

    @Autowired
    private IUserInfoService service;

    @RequestMapping(value = "/list",method = RequestMethod.GET)
    public String getlist(HttpServletRequest request, HttpServletResponse response) throws IOException {
        try {
            this.validPermission(request,"UserManage");
        } catch (Exception e) {
            return this.exp(response,e);
        }
        return "userinfo/list";
    }

    @RequestMapping(value = "/list",method = RequestMethod.POST)
    @ResponseBody
    public List<UserInfo> list() throws Exception {
        return this.service.getAllUsers();
    }

    @RequestMapping(value = "/add",method = RequestMethod.GET)
    public String getadd(HttpServletRequest request,HttpServletResponse response) throws IOException {
        try {
            this.validPermission(request,"UserManage");
        } catch (Exception e) {
            return this.exp(response,e);
        }
        return "userinfo/add";
    }

    @RequestMapping(value = "/add",method = RequestMethod.POST)
    @ResponseBody
    public String add(HttpServletRequest request){
        UserInfo user = new UserInfo();
        user.setUsername(request.getParameter("Username"));
        user.setPassword(request.getParameter("Password"));
        try {
            this.service.insertUser(user);
            return "success";
        } catch (Exception e) {
            return e.getMessage();
        }
    }

    @RequestMapping(value = "/delete",method = RequestMethod.POST)
    @ResponseBody
    public String delete(HttpServletRequest request){
        try {
            this.validPermission(request,"UserManage");
            String id = request.getParameter("id");
            this.service.deleteUser(Integer.parseInt(id));
            return "success";
        } catch (Exception e) {
            return e.getMessage();
        }
    }

    @RequestMapping(value = "/getedit",method = RequestMethod.GET)
    public String getEdit(HttpServletRequest request,HttpServletResponse response,Model model) throws Exception {
        try {
            this.validPermission(request,"UserManage");
        } catch (Exception e) {
            return this.exp(response,e);
        }
        UserInfo user = this.service.getUserById(Integer.parseInt(request.getParameter("id")));
        model.addAttribute("selectUser",user);
        return "/userinfo/edit";
    }

    @RequestMapping(value = "/edit", method = RequestMethod.POST)
    @ResponseBody
    public String Edit(HttpServletRequest request){
        UserInfo user = new UserInfo();
        user.setId(Integer.parseInt(request.getParameter("Id")));
        user.setUsername(request.getParameter("Username"));
        user.setPassword(request.getParameter("Password"));
        try {
            this.service.updateUser(user);
            return "success";
        } catch (Exception e) {
            return e.getMessage();
        }
    }

    @RequestMapping(value = "/getdetail",method = RequestMethod.GET)
    public String getDetail(HttpServletRequest request,Model model) throws Exception {
        UserInfo user = this.service.getUserById(Integer.parseInt(request.getParameter("id")));
        model.addAttribute("selectUser",user);
        return "/userinfo/detail";
    }

}
