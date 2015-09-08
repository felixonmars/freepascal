
function LOBYTE(w: Word): Byte; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function HIBYTE(w: Word): Byte; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function LOWORD(l: LongInt): Word; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function HIWORD(l: LongInt): Word; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function MAKELONG(low, high: Word): LONG; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function MAKELPARAM(low, high: Word): LPARAM; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function MAKELRESULT(low, high: Word): LRESULT; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function MAKELP(sel, off: Word): FarPointer; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function SELECTOROF(lp: FarPointer): Word; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function OFFSETOF(lp: FarPointer): Word; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

// FIELDOFFSET

{ System Information }
function GetVersion: DWORD; external 'KERNEL';

function GetFreeSpace(Flag: UINT): DWORD; external 'KERNEL';
function GetCurrentPDB: UINT; external 'KERNEL';

function GetWindowsDirectory(Buffer: LPSTR; Size: UINT): UINT; external 'KERNEL';
function GetSystemDirectory(Buffer: LPSTR; Size: UINT): UINT; external 'KERNEL';

function GetWinFlags: DWORD; external 'KERNEL';

function GetDOSEnvironment: LPSTR; external 'KERNEL';

function GetCurrentTime: DWORD; external 'USER';
function GetTickCount: DWORD; external 'USER';
function GetTimerResolution: DWORD; external 'USER';

{ Error handling }
procedure FatalExit(Code: SmallInt); external 'KERNEL';
procedure FatalAppExit(Action: UINT; MessageText: LPCSTR); external 'KERNEL';

function ExitWindows(dwReturnCode: DWORD; wReserved: UINT): BOOL; external 'USER';

procedure DebugBreak; external 'KERNEL';
procedure OutputDebugString(OutputString: LPCSTR); external 'KERNEL';

function SetErrorMode(Mode: UINT): UINT; external 'KERNEL';

{ Catch/Throw and stack management }

function Catch(CatchBuf: LPCATCHBUF): SmallInt; external 'KERNEL';
procedure Throw(CatchBuf: LPCATCHBUF; ThrowBack: SmallInt); external 'KERNEL';
{$ifdef VAR_PARAMS_ARE_FAR}
function Catch(var CatchBuf: TCatchBuf): SmallInt; external 'KERNEL';
procedure Throw(var CatchBuf: TCatchBuf; ThrowBack: SmallInt); external 'KERNEL';
{$endif}

procedure SwitchStackBack; external 'KERNEL';
procedure SwitchStackTo(StackSegment, StackPointer, StackTop: UINT); external 'KERNEL';

{ Module Management }

function LoadModule(ModuleName: LPCSTR; ParameterName: LPVOID): HINST; external 'KERNEL';
function FreeModule(Module: HINST): BOOL; external 'KERNEL';

function LoadLibrary(LibFileName: LPCSTR): HINST; external 'KERNEL';
procedure FreeLibrary(LibModule: HINST); external 'KERNEL';

function WinExec(CmdLine: LPCSTR; CmdShow: UINT): UINT; external 'KERNEL';

function GetModuleHandle(ModuleName: LPCSTR): HMODULE; external 'KERNEL';

function GetModuleUsage(Module: HINST): SmallInt; external 'KERNEL';
function GetModuleFileName(Module: HINST; FileName: LPSTR; Size: SmallInt): SmallInt; external 'KERNEL';

function GetProcAddress(Module: HINST; ProcName: LPCSTR): FARPROC; external 'KERNEL';

function GetInstanceData(Instance: HINST; Data: PBYTE; Count: SmallInt): SmallInt; external 'KERNEL';

function GetCodeHandle(Proc: FARPROC): HGLOBAL; external 'KERNEL';

procedure GetCodeInfo(lpProc: FARPROC; lpSegInfo: LPSEGINFO); external 'KERNEL';

function MakeProcInstance(Proc: FARPROC; Instance: HINST): FARPROC; external 'KERNEL';
procedure FreeProcInstance(Proc: FARPROC); external 'KERNEL';

{#ifdef _LAX
#define MakeProcInstance(__F, __H) MakeProcInstance((FARPROC)__F, __H)
#define FreeProcInstance(__F)      FreeProcInstance((FARPROC)__F)
#endif /* _LAX */}

function SetSwapAreaSize(Size: UINT): LONG; external 'KERNEL';
procedure SwapRecording(Flag: UINT); external 'KERNEL';
procedure ValidateCodeSegments; external 'KERNEL';

{ Task Management }

function GetNumTasks: UINT; external 'KERNEL';
function GetCurrentTask: HTASK; external 'KERNEL';

procedure Yield; external 'KERNEL';
procedure DirectedYield(Task: HTASK); external 'KERNEL';

{ Global memory management }

function GlobalDiscard(h: HGLOBAL): HGLOBAL; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function GlobalAlloc(Flags: UINT; Bytes: DWORD): HGLOBAL; external 'KERNEL';
function GlobalReAlloc(Mem: HGLOBAL; Bytes: DWORD; Flags: UINT): HGLOBAL; external 'KERNEL';
function GlobalFree(Mem: HGLOBAL): HGLOBAL; external 'KERNEL';

function GlobalDosAlloc(Bytes: DWORD): DWORD; external 'KERNEL';
function GlobalDosFree(Selector: UINT): UINT; external 'KERNEL';

function GlobalLock(Mem: HGLOBAL): FarPointer; external 'KERNEL';
function GlobalUnlock(Mem: HGLOBAL): BOOL; external 'KERNEL';

function GlobalSize(Mem: HGLOBAL): DWORD; external 'KERNEL';
function GlobalHandle(Mem: UINT): DWORD; external 'KERNEL';

function GlobalFlags(Mem: HGLOBAL): UINT; external 'KERNEL';

function GlobalWire(Mem: HGLOBAL): FarPointer; external 'KERNEL';
function GlobalUnWire(Mem: HGLOBAL): BOOL; external 'KERNEL';

function GlobalPageLock(Selector: HGLOBAL): UINT; external 'KERNEL';
function GlobalPageUnlock(Selector: HGLOBAL): UINT; external 'KERNEL';

procedure GlobalFix(Mem: HGLOBAL); external 'KERNEL';
procedure GlobalUnfix(Mem: HGLOBAL); external 'KERNEL';

function GlobalLRUNewest(Mem: HGLOBAL): HGLOBAL; external 'KERNEL';
function GlobalLRUOldest(Mem: HGLOBAL): HGLOBAL; external 'KERNEL';

function GlobalCompact(MinFree: DWORD): DWORD; external 'KERNEL';

procedure GlobalNotify(NotifyProc: GNOTIFYPROC); external 'KERNEL';

function LockSegment(Segment: UINT): HGLOBAL; external 'KERNEL';
procedure UnlockSegment(Segment: UINT); external 'KERNEL';

function LockData(dummy: SmallInt): HGLOBAL; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
procedure UnlockData(dummy: SmallInt); {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function AllocSelector(Selector: UINT): UINT; external 'KERNEL';
function FreeSelector(Selector: UINT): UINT; external 'KERNEL';
function AllocDStoCSAlias(Selector: UINT): UINT; external 'KERNEL';
function PrestoChangoSelector(sourceSel, destSel: UINT): UINT; external 'KERNEL';
function GetSelectorBase(Selector: UINT): DWORD; external 'KERNEL';
function SetSelectorBase(Selector: UINT; Base: DWORD): UINT; external 'KERNEL';
function GetSelectorLimit(Selector: UINT): DWORD; external 'KERNEL';
function SetSelectorLimit(Selector: UINT; Base: DWORD): UINT; external 'KERNEL';

procedure LimitEmsPages(Kbytes: DWORD); external 'KERNEL';

procedure ValidateFreeSpaces; external 'KERNEL';

{ Local Memory Management }

function LocalDiscard(h: HLOCAL): HLOCAL; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function LocalAlloc(Flags, Bytes: UINT): HLOCAL; external 'KERNEL';
function LocalReAlloc(Mem: HLOCAL; Bytes, Flags: UINT): HLOCAL; external 'KERNEL';
function LocalFree(Mem: HLOCAL): HLOCAL; external 'KERNEL';

function LocalLock(Mem: HLOCAL): NearPointer; external 'KERNEL';
function LocalUnlock(Mem: HLOCAL): BOOL; external 'KERNEL';

function LocalSize(Mem: HLOCAL): UINT; external 'KERNEL';
function LocalHandle(Mem: NearPointer): HLOCAL; external 'KERNEL';

function LocalFlags(Mem: HLOCAL): UINT; external 'KERNEL';

function LocalInit(Segment, Start, EndPos: UINT): BOOL; external 'KERNEL';
function LocalCompact(MinFree: UINT): UINT; external 'KERNEL';
function LocalShrink(Seg: HLOCAL; Size: UINT): UINT; external 'KERNEL';

{ File I/O }

function OpenFile(FileName: LPCSTR; ReOpenBuff: LPOFSTRUCT; Style: UINT): HFILE; external 'KERNEL';
{$ifdef VAR_PARAMS_ARE_FAR}
function OpenFile(FileName: LPCSTR; var ReOpenBuff: TOFStruct; Style: UINT): HFILE; external 'KERNEL';
{$endif}

function _lopen(PathName: LPCSTR; ReadWrite: SmallInt): HFILE; external 'KERNEL';
function _lcreat(PathName: LPCSTR; Attribute: SmallInt): HFILE; external 'KERNEL';

function _lclose(FileHandle: HFILE): HFILE; external 'KERNEL';

function _llseek(FileHandle: HFILE; Offset: LONG; Origin: SmallInt): LONG; external 'KERNEL';

function _lread(FileHandle: HFILE; Buffer: HugePointer; Bytes: UINT): UINT; external 'KERNEL';
function _lread(FileHandle: HFILE; Buffer: FarPointer; Bytes: UINT): UINT; external 'KERNEL';
function _lwrite(FileHandle: HFILE; Buffer: HugePointer; Bytes: UINT): UINT; external 'KERNEL';
function _lwrite(FileHandle: HFILE; Buffer: FarPointer; Bytes: UINT): UINT; external 'KERNEL';

function GetTempFileName(DriveLetter: BYTE; PrefixString: LPCSTR; Unique: UINT; TempFileName: LPSTR): SmallInt; external 'KERNEL';
function GetTempFileName(DriveLetter: Char; PrefixString: LPCSTR; Unique: UINT; TempFileName: LPSTR): SmallInt; external 'KERNEL';
function GetTempDrive(DriveLetter: Char): BYTE; external 'KERNEL';

function GetDriveType(Drive: SmallInt): UINT; external 'KERNEL';

function SetHandleCount(Number: UINT): UINT; external 'KERNEL';

{ Network support }
function WNetAddConnection(lpszNetPath, lpszPassword, lpszLocalName: LPSTR): UINT; external 'USER';
function WNetGetConnection(lpszLocalName, lpszRemoteName: LPSTR; cbBufferSize: LPUINT): UINT; external 'USER';
function WNetCancelConnection(lpszName: LPSTR; tForce: BOOL): UINT; external 'USER';
