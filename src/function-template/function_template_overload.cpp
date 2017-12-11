/*
 * cpp-primer, my own love
 * Copyright (C) <2017>  <zhangsheng@4399inc.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Created by <zhangsheng@4399inc.com> on 2017-12-11.
 */
//void ftoo_swap(int &a, int &b) {
//  int temp = a;
//  a = b;
//  b = temp;
//}

template<typename T>
void ftoo_swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

//template<typename T>
//void ftoo_swap(T a[], T b[], int n) {
//  T temp;
//  for (int i = 0; i < n; i++) {
//    temp = b[i];
//    b[i] = a[i];
//    a[i] = temp[i];
//  }
//}


