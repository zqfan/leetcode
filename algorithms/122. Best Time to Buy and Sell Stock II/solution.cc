/* Copyright (C) 2013 ZhiQiang Fan <aji.zqfan@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for ( int i = 1; i < prices.size(); i++ ) {
            int p = prices[i] - prices[i-1];
            profit += p > 0 ? p : 0;
        }
        return profit;
    }
};
