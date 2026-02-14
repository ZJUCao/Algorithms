# merge sort two halves in descending order
def mergeSort(left, right):
    i = 0
    j = 0
    count = 0
    merged = []
    
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            # right[j] is taller than left[i] AND taller than 
            # all remaining elements in the left list.
            count += (len(left) - i)
            merged.append(right[j])
            j += 1
        else:
            merged.append(left[i])
            i += 1
            
    # Append remaining elements
    merged.extend(left[i:])
    merged.extend(right[j:])
    
    return merged, count

def leftPeaks(peaks):
    """
    Computes the total number of left peaks in O(n log n) time
    using a divide and conquer approach similar to merge sort.
    """
    if len(peaks) <= 1:
        return peaks, 0
    
    mid = len(peaks) // 2
    left, leftCnt = leftPeaks(peaks[:mid])
    right, rightCnt = leftPeaks(peaks[mid:])
    
    merged, mergeCnt = mergeSort(left, right)
    
    return merged, (leftCnt + rightCnt + mergeCnt)

# input n
n = int(input())

# input n peaks
peaks = []
while (len(peaks) < n):
    peaks.extend(list(map(int, input().split())))

peaks, result = leftPeaks(peaks)
print(result)