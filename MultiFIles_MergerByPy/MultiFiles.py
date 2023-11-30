import ctypes
from os import add_dll_directory, path

add_dll_directory(path.abspath('../MultiFiles/x64/Release'))
MultiFiles = ctypes.CDLL('MultiFiles.dll')

class MultiFilesMerger:
    def __init__(self) -> None:
        MultiFiles.merge.argtypes = [ctypes.Array(ctypes.c_char_p), ctypes.c_char_p, ctypes.c_char_p]
        MultiFiles.merge.restype = ctypes.c_void_p
    
    def merge(self, toGenFiles, toGenFileName="merged.tffs", infoFileName="merged-info.txt"):
        MultiFiles.merge(toGenFiles, toGenFileName, infoFileName)




