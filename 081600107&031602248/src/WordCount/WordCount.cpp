// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "stdafx.h"
#include "core.h"

int main(int argc, char* argv[]) {
	// 指令处理
	char in_name[100], out_name[100];
	int n = 10, m = 1, w = 1;
	rep(i, 1, argc) {
		if (argv[i][1] == 'i') strcpy_s(in_name, argv[i+1]);
		if (argv[i][1] == 'o') strcpy_s(out_name, argv[i + 1]);
		if (argv[i][1] == 'w') {
			if (argv[i + 1][0] == '0') w = 1; else w = 10;
		}
		if (argv[i][1] == 'm') m = atoi(argv[i + 1]);
		if (argv[i][1] == 'n') n = atoi(argv[i + 1]);
		i++;
	}
	FILE *stream;
	freopen_s(&stream,out_name, "w", stdout);

	// 单词处理函数
	int now = -1;
	int characters = CountChar(in_name);
	pii tmp = CountWord(in_name);
	int words = tmp.fi, lines = tmp.se;
	vector<pair<string, int> > ans;
	ans = CountFrequentWord(in_name, w, m);
	cout << "characters: " << characters << endl;
	cout << "words: " << words << endl;
	cout << "lines: " << lines << endl;
	int nn = sz(ans);
	if (nn > n) nn = n;
	rep(i, 0, nn) cout << "<" << ans[i].fi << ">: " << ans[i].se << endl;
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
