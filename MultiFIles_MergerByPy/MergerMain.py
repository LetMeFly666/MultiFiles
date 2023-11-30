
import MultiFiles

print(MultiFiles.MultiFiles)
multiFilesMerger = MultiFiles.MultiFilesMerger()
print(multiFilesMerger)
print(multiFilesMerger.merge(toGenFiles=["MultiFiles_ToMerge_SmallFiles/00000001.txt", "MultiFiles_ToMerge_SmallFiles/00000002.txt"]))