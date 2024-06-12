/*
 * Floor
 * Logic
 */

int nextNum(int *nums1, int nums1Size, int *nums2, int nums2Size, int *index1, int *index2)
{
    if (nums1Size < 0 || nums2Size < 0 || nums1 == NULL || nums2 == NULL || index1 == NULL || index2 == NULL)
        return -1;

    int isNum1Remain = 0;
    int isNum2Remain = 0;

    isNum1Remain = *index1 < nums1Size;
    isNum2Remain = *index2 < nums2Size;

    if (isNum1Remain && isNum2Remain)
    {
        return (nums1[*index1] < nums2[*index2]) ? nums1[(*index1)++] : nums2[(*index2)++];
    }
    else if (isNum1Remain)
    {
        return nums1[(*index1)++];
    }
    else
    {
        return nums2[(*index2)++];
    }
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    if (nums1Size < 0 || nums2Size < 0 || nums1 == NULL || nums2 == NULL)
        return -1;

    int medianLeftIdx = 0;
    int medianRightIdx = 0;
    int index1 = 0;
    int index2 = 0;
    int total = 0;
    int i = 0;
    double numGet = 0;
    double result = 0;

    total = nums1Size + nums2Size;
    if (total % 2)
    {
        medianLeftIdx = (total >> 1) + 1;
        medianRightIdx = medianLeftIdx;
    }
    else
    {
        medianLeftIdx = total >> 1;
        medianRightIdx = medianLeftIdx + 1;
    }

    while (i < total)
    {
        numGet = nextNum(nums1, nums1Size, nums2, nums2Size, &index1, &index2);
        ++i;
        if (i == medianLeftIdx)
        {
            result = numGet;
        }
        if (i == medianRightIdx)
        {
            result += numGet;
            break;
        }
    }

    return result / 2.0;
}