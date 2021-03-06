//
//  FileDir.h
//  FileDir
//
//  Created by Daniel Cohen Gindi on 6/24/14.
//  Copyright (c) 2013 Daniel Cohen Gindi. All rights reserved.
//
//  https://github.com/danielgindi/FileDir
//
//  The MIT License (MIT)
//
//  Copyright (c) 2014 Daniel Cohen Gindi (danielgindi@gmail.com)
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
//

#pragma once

#include <ctime>

class FileDir
{
	friend class FileDirController;
public:
	FileDir(void);
	virtual ~FileDir(void);

	// Returns the full path including drive letter, base path, and file/folder name
#ifdef _WIN32 /* Wide char */
	inline const wchar_t * GetFullPath() { return _fullPath; }
#else
	inline const char * GetFullPath() { return _fullPath; }
#endif

	// Sets the full path including drive letter, base path, and file/folder name
#ifdef _WIN32 /* Wide char */
	void SetFullPath(const wchar_t *fullPath);
#else
	void SetFullPath(const char *fullPath);
#endif

	// Returns the file name including extension, without base path
#ifdef _WIN32 /* Wide char */
	inline const wchar_t * GetFileName() { return _fileName; }
#else
	inline const char * GetFileName() { return _fileName; }
#endif

	// Returns the extension without the period
#ifdef _WIN32 /* Wide char */
	const wchar_t * GetExtension();
#else
	const char * GetExtension();
#endif

	// Returns the file name without the extension
#ifdef _WIN32 /* Wide char */
	const wchar_t * GetFileNameWithoutExtension();
#else
	const char * GetFileNameWithoutExtension();
#endif

	// Returns the path without the filename
#ifdef _WIN32 /* Wide char */
	const wchar_t * GetBasePath();
#else
	const char * GetBasePath();
#endif

	// Is this a folder?
	inline bool IsFolder() { return _isFolder; }

	// Is this a file?
	inline bool IsFile() { return _isFile; }

	// Get the last modified time
	time_t GetLastModified();

	// Get the creation time
	time_t GetCreationTime();

	// Get the last access time
	time_t GetLastAccessTime();

	// Get the last status change time
	time_t GetLastStatusChangeTime();

private:

#ifdef _WIN32 /* Wide char */
	wchar_t *_fullPath;
	wchar_t *_fileName;
#else /* UTF8 */
	char *_fullPath;
	char *_fileName;
#endif

	bool _isFolder;
	bool _isFile;
	bool _hasTimes;

	time_t _creationTime;
	time_t _lastModificationTime;
	time_t _lastAccessTime;
	time_t _lastStatusChangeTime;

#ifdef _WIN32 /* Wide char */
	wchar_t *_cachedExtension;
	wchar_t *_cachedFileNameWithoutExtension;
	wchar_t *_cachedBasePath;
#else /* UTF8 */
	char *_cachedExtension;
	char *_cachedFileNameWithoutExtension;
	char *_cachedBasePath;
#endif
};

