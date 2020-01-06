// 弹出信息窗口 title:标题 msgString:提示信息 msgType:信息类型 [error,info,question,warning]
function showMsg(title, msgString, msgType) {
    $.messager.alert(title, msgString, msgType);
}

// 显示提示信息
function showInfo(msg) {
    showMsg("温馨提示", msg, "info");
}

// 显示警告信息
function showWarning(msg) {
    showMsg("温馨提示", msg, "warning");
}

// 显示错误信息
function showError(msg) {
    showMsg("温馨提示", msg, "error");
}

// 在窗体右下角显示提示框
function showWindowMsg(msg) {
    $.messager.show({
        title: '温馨提示',
        msg: msg,
        timeout: 10000,
        showType: 'show'
    });
}

//在窗体右下角显示提示框，可设置显示时间
function showWinMsg(msg,time) {
    $.messager.show({
        title: '温馨提示',
        msg: msg,
        timeout: time*1000,
        showType: 'show'
    });
}

// 获取url中某个参数值
function getQueryString(name) {
    var reg = new RegExp("(^|&)" + name + "=([^&]*)(&|$)", "i");
    var r = window.location.search.substr(1).match(reg);
    if (r != null) return decodeURI(r[2]); return null;
}

// 创建一个不会重复的Id
function createId() {
    var id = "id" + (new Date()).getTime() + parseInt(Math.random() * 100000);
    return id;
}

// 打开一个新创建的弹出窗体
function openCreatWindow(title, href, width, height, modal, minimizable, maximizable, icon) {
    var winId = createId();
    window.top.$('body').append('<div id="' + winId + '" class="easyui-dialog" closed="true"></div>');

    href += "&WindowDivId=" + winId;
    
    window.top.$('#' + winId).window({
        title: title,
        width: width === undefined ? 600 : width,
        height: height === undefined ? 400 : height,
        content: '<iframe scrolling="no" frameborder="0"  src="' + href + '" style="width:100%;height:98%;"></iframe>',
        modal: modal === undefined ? true : modal,
        minimizable: minimizable === undefined ? false : minimizable,
        maximizable: maximizable === undefined ? false : maximizable,
        shadow: false,
        cache: false,
        closed: false,
        collapsible: false,
        resizable: false,
        iconCls: icon === undefined ? "" : icon,
        loadingMessage: '正在加载数据，请稍候...'
    });
}

//打开一个普通窗口，不做刷新处理
function showWindowNoRefresh(title, url, icon, showModal)
{
    if (top.location == self.location || showModal) {
        if (url.indexOf("?") <= 0) {
            url += "/?open=true";
        }
        openCreatWindow(title, url, 800, 500, true, false, true, icon);
    }
    else {
        window.top.addTab(title, url, icon);
    }
}

// 如果不是顶级窗口，则在Tabs中打开一个窗体。
// 否则，打开一个模式窗体。
// 如果有明确要求，也是打开一个模式窗体。
function showWindow(title, url, icon, reloadId, reloadType, showModal) {
    if (url.indexOf("?") > 0)
    {
        url += "&";
    }
    else
    {
        url += "/?"
    }

    url += "ReloadControl=" + reloadId + "&ReloadControlType=" + reloadType;
    if (window.top.getCurrentTabTitle)
    {
        var fromTabTitle = window.top.getCurrentTabTitle();
        url += "&FromTabTitle=" + fromTabTitle;
    }

    if (top.location == self.location || showModal) {
        openCreatWindow(title, url, 800, 500, true, false, true, icon);
    }
    else {
        window.top.addTab(title, url, icon);
    }
}

// 如果不是顶级窗口，则关闭当前的Tab窗体。
// 否则，关闭一个模式窗体。
function closeWindow()
{
    var winId = getQueryString('WindowDivId');
    var win = window.top.document.getElementById(winId);
    
    if (win) {
        window.top.$("#" + winId).window('close');
    }
    else {
        if (window.top.closeCurrentTab) {
            window.top.closeCurrentTab();
        }
        else {
            window.close();
        }
    }
}

// 打开一个模式窗体
function showModalWindow(title, url, icon)
{
    window.top.openCreatWindow(title, url, 800, 500, true, false, true, icon);
}

// 关闭一个模式窗体
function closeModalWindow() {
    var winId = getQueryString('WindowDivId');
    window.top.$("#" + winId).window('close');
}

// 显示一个选择对话框：
// url：请求地址。
// singleSelect：是否单选；
// from：事件源；
// title：对话框标题；
// queryParam：查询参数
// 调用选择对话框的Window需要实现returnChooseValue(text, value,from)回调方法。
function showChooseDialog(url, singleSelect, from, title) {
    var winId = createId();
    window.top.$('body').append('<div id="' + winId + '" class="easyui-dialog" closed="true"></div>');

    url = url + "/?ChooseDialogId=" + winId + "&ViewName=Choose&SingleSelect=" + singleSelect + "&From=" + from;
    
    if (arguments[4])
    {
        url += "&QueryParams=" + arguments[4];
    }

    window.top.$('#' + winId).window({
        title: title,
        width: 900,
        height: 500,
        content: '<iframe scrolling="no" frameborder="0"  src="' + url + '" style="width:100%;height:98%;"></iframe>',
        modal: true,
        minimizable: false,
        maximizable: true,
        shadow: false,
        cache: false,
        closed: false,
        collapsible: false,
        resizable: false,
        loadingMessage: '处理中，请稍候...'
    });
}