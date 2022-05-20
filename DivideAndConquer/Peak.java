import java.util.*;

class Ideone {
    public static void main(String[] args) throws java.lang.Exception {
        new Ideone().run();
    }

    int N, M;

    void run() {
        N = 1000;
        M = 100;

        // arr is a random NxM array
        int[][] arr = randomArray();
        long start = System.currentTimeMillis();
        // for(int i=0; i<N; i++){ // TO print the array.
        // System. out.println(Arrays.toString(arr[i]));
        // }
        System.out.println(findPeakLinearTime(arr));
        long end = System.currentTimeMillis();
        System.out.println("time taken : " + (end - start));
    }

    int findPeakLinearTime(int[][] arr) {
        int rows = arr.length;
        int cols = arr[0].length;
        return kthLinearColumn(arr, 0, cols - 1, 0, rows - 1);
    }

    int getColMax(int[][] arr, int col, int loRow, int hiRow) {
        int max = 0;
        for (int row = loRow; row <= hiRow; row++) {
            if (arr[row][col] > max) {
                max = arr[row][col];
            }
        }
        return max;
    }

    int getRowMax(int[][] arr, int col, int loRow, int hiRow) {
        int max = 0;
        for (int row = loRow; row <= hiRow; row++) {
            if (arr[row][col] > max) {
                max = arr[row][col];
            }
        }
        return max;
    }

    // helper function that splits on the middle Column
    int kthLinearColumn(int[][] arr, int loCol, int hiCol, int loRow, int hiRow) {
        if (loCol == hiCol) {
            int max = arr[loRow][loCol];
            int foundRow = loRow;
            for (int row = loRow; row <= hiRow; row++) {
                if (max < arr[row][loCol]) {
                    max = arr[row][loCol];
                    foundRow = row;
                }
            }
            if (!correctPeak(arr, foundRow, loCol)) {
                System.out.println("THIS PEAK IS WRONG");
            }
            return max;
        }
        int midCol = (loCol + hiCol) / 2;
        int max = arr[loRow][loCol];
        for (int row = loRow; row <= hiRow; row++) {
            max = Math.max(max, arr[row][midCol]);
        }
        boolean centralMax = true;
        boolean rightMax = false;
        boolean leftMax = false;

        if (midCol - 1 >= 0) {
            for (int row = loRow; row <= hiRow; row++) {
                if (arr[row][midCol - 1] > max) {
                    max = arr[row][midCol - 1];
                    centralMax = false;
                    leftMax = true;
                }
            }
        }

        if (midCol + 1 < M) {
            for (int row = loRow; row <= hiRow; row++) {
                if (arr[row][midCol + 1] > max) {
                    max = arr[row][midCol + 1];
                    centralMax = false;
                    leftMax = false;
                    rightMax = true;
                }
            }
        }

        if (centralMax)
            return max;
        if (rightMax)
            return kthLinearRow(arr, midCol + 1, hiCol, loRow, hiRow);
        if (leftMax)
            return kthLinearRow(arr, loCol, midCol - 1, loRow, hiRow);
        throw new RuntimeException("INCORRECT CODE");
    }

    // helper function that splits on the middle
    int kthLinearRow(int[][] arr, int loCol, int hiCol, int loRow, int hiRow) {
        if (loRow == hiRow) {
            int ans = arr[loCol][loRow];
            int foundCol = loCol;
            for (int col = loCol; col <= hiCol; col++) {
                if (arr[loRow][col] > ans) {
                    ans = arr[loRow][col];
                    foundCol = col;
                }
            }
            if (!correctPeak(arr, loRow, foundCol)) {
                System.out.println("THIS PEAK IS WRONG");
            }
            return ans;
        }
        boolean centralMax = true;
        boolean upperMax = false;
        boolean lowerMax = false;

        int midRow = (loRow + hiRow) / 2;
        int max = arr[midRow][loCol];

        for (int col = loCol; col <= hiCol; col++) {
            max = Math.max(max, arr[midRow][col]);
        }

        if (midRow - 1 >= 0) {
            for (int col = loCol; col <= hiCol; col++) {
                if (arr[midRow - 1][col] > max) {
                    max = arr[midRow - 1][col];
                    upperMax = true;
                    centralMax = false;
                }
            }
        }

        if (midRow + 1 < N) {
            for (int col = loCol; col <= hiCol; col++) {
                if (arr[midRow + 1][col] > max) {
                    max = arr[midRow + 1][col];
                    lowerMax = true;
                    centralMax = false;
                    upperMax = false;
                }
            }
        }

        if (centralMax)
            return max;
        if (lowerMax)
            return kthLinearColumn(arr, loCol, hiCol, midRow + 1, hiRow);
        if (upperMax)
            return kthLinearColumn(arr, loCol, hiCol, loRow, midRow - 1);
        throw new RuntimeException("Incorrect code");
    }

    int[][] randomArray() {
        int[][] arr = new int[N][M];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                arr[i][j] = (int) (Math.random() * 1000000000);
        return arr;
    }

    boolean correctPeak(int[][] arr, int row, int col) {// Function that checks if arr[row][col] is a peak or not
        if (row - 1 >= 0 && arr[row - 1][col] > arr[row][col])
            return false;
        if (row + 1 < N && arr[row + 1][col] > arr[row][col])
            return false;
        if (col - 1 >= 0 && arr[row][col - 1] > arr[row][col])
            return false;
        if (col + 1 < M && arr[row][col + 1] > arr[row][col])
            return false;
        return true;
    }
}