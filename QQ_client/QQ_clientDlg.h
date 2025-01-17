// QQ_clientDlg.h : header file
//

#if !defined(AFX_QQ_CLIENTDLG_H__A2C45C50_250A_4C16_833C_B3F2DBF95D75__INCLUDED_)
#define AFX_QQ_CLIENTDLG_H__A2C45C50_250A_4C16_833C_B3F2DBF95D75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TalkDlg.h"
#include "GAME_RULE.h"

//自定义消息
#define WM_SOCKET WM_USER+100

/////////////////////////////////////////////////////////////////////////////
// CQQ_clientDlg dialog

class CQQ_clientDlg : public CDialog
{
// Construction
public:
	CQQ_clientDlg(CWnd* pParent = NULL);	// standard constructor

	//解析信息
	CString getKeyMsg(CString recv_msg,CString keyword);

	//对列表控件的操作
	void AddMem(CString name);				//增加成员
	void UpdateList(CString MemList);		//更新成员显示列表

	//对显示在对话框中的信息做处理
	void SetMessage(CString msg);			//设置显示在“结果”编辑框中的内容
	void SetScore(CString msg);				//设置显示在“积分”编辑框中的内容
	void Namenotused();						//如果用户输入的昵称没有使用过的逻辑事件

public:
	SOCKET		socket_client;
	CString 	from_name;			//保存用户名信息
	CString		to_name;			//保存接收者信息

// Dialog Data
	//{{AFX_DATA(CQQ_clientDlg)
	enum { IDD = IDD_QQ_CLIENT_DIALOG };
	CEdit	m_recv;
	CListCtrl	m_listmem;
	CString	m_username;
	CString	m_sendcard;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQQ_clientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON		m_hIcon;
	CImageList	m_imagelist;
	int			index_image;
	CTalkDlg	m_dlg;
	GAME_RULE   m_GR_dlg;

	// Generated message map functions
	//{{AFX_MSG(CQQ_clientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	virtual void OnCancel();
	afx_msg void OnDblclkListmem(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnGameRulebtn();
	afx_msg void OnGameStart();
	afx_msg void OnChangeSendCard();
	afx_msg void OnSendsure();
	//}}AFX_MSG
	afx_msg void OnSocket(WPARAM wParam,LPARAM lParam);		//自定义消息的响应函数
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QQ_CLIENTDLG_H__A2C45C50_250A_4C16_833C_B3F2DBF95D75__INCLUDED_)
