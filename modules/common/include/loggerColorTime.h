#ifndef __3MB_LOGGER_H_
#define __3MB_LOGGER_H_

#define 3MB_DEBUG_LOGS
//#undef 3MB_DEBUG_LOGS	// Uncomment to avoid logs

#	ifdef 3MB_DEBUG_LOGS
		// YES LOGS
#		ifdef ANDROID
			// LOGS ANDROID
#			include <android/log.h>
#			define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG,__VA_ARGS__)
#			define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG  , LOG_TAG,__VA_ARGS__)
#			define LOGI(...) __android_log_print(ANDROID_LOG_INFO   , LOG_TAG,__VA_ARGS__)
#			define LOGW(...) __android_log_print(ANDROID_LOG_WARN   , LOG_TAG,__VA_ARGS__)
#			define LOGE(...) __android_log_print(ANDROID_LOG_ERROR  , LOG_TAG,__VA_ARGS__)
#			define LOGSIMPLE(...)
#		elif WIN32
#		include <windows.h>
#		include <stdio.h>
#		include <time.h>
		//cuidado con esto si en algún momento hacemos multithreading!!!
		static char buff[100];
		static struct tm *sTm;
		static time_t now;
#		define PRINT_TIME \
			now = time(0); \
			sTm = localtime(&now); \
			strftime(buff, sizeof(buff), "[%Y-%m-%d %H:%M:%M]", sTm); \
			fprintf(stdout, "%s ", buff);
#		define LOGV(...) PRINT_TIME SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN); fprintf(stdout, "[V] [%s] ", LOG_TAG); fprintf(stdout, __VA_ARGS__); fprintf(stdout, "\n");										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
#		define LOGD(...) PRINT_TIME SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN); fprintf(stdout, "[D] [%s] ", LOG_TAG); fprintf(stdout, __VA_ARGS__); fprintf(stdout, "\n");											SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
#		define LOGI(...) PRINT_TIME SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN); fprintf(stdout, "[I] [%s] ", LOG_TAG); fprintf(stdout, __VA_ARGS__); fprintf(stdout, "\n");											SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
#		define LOGW(...) PRINT_TIME SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED); fprintf(stdout, "[W] [%s] ", LOG_TAG); fprintf(stdout, __VA_ARGS__); fprintf(stdout, "\n");						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
#		define LOGE(...) PRINT_TIME SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED); fprintf(stdout, "[E] [%s] ", LOG_TAG); fprintf(stdout, __VA_ARGS__); fprintf(stdout, "\n");											SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
#		define LOGSIMPLE(...) printf(" ");printf(__VA_ARGS__);
#		else
			// LOGS NO ANDROID
#		include <stdio.h>
#		include <time.h>
		// Warning multithreading!!!
		static char buff[100];
		static struct tm *sTm;
		static time_t now;
#		define PRINT_TIME \
			now = time(0); \
			sTm = localtime(&now); \
			strftime(buff, sizeof(buff), "[%Y-%m-%d %H:%M:%M]", sTm); \
			fprintf(stderr, "%s ", buff);
#		define LOGV(...) PRINT_TIME fprintf(stderr, "[Verbose] [%s] ", LOG_TAG); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n");
#		define LOGD(...) PRINT_TIME fprintf(stderr, "[Debug] [%s] ", LOG_TAG); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n");
#		define LOGI(...) PRINT_TIME fprintf(stderr, "[Info] [%s] ", LOG_TAG); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n");
#		define LOGW(...) PRINT_TIME fprintf(stderr, "[Warning] [%s] ", LOG_TAG); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n");
#		define LOGE(...) PRINT_TIME fprintf(stderr, "[Error] [%s] ", LOG_TAG); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n");
#		define LOGSIMPLE(...) printf(" ");printf(__VA_ARGS__);
#		endif // ANDROID
#	else
		// NO LOGS
#		define LOGV(...)
#		define LOGD(...)
#		define LOGI(...)
#		define LOGW(...)
#		define LOGE(...)
#		define LOGSIMPLE(...)
#	endif // 3MB_DEBUG_LOGS
#endif // __3MB_LOGGER_H_
