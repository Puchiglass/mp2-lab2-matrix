// ����, �����, ���� "��������� � ��������� ������"
//
// Copyright (c) ������ �.�.
//
//

#pragma once

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;


// ������������ ������ - 
// ��������� ������ �� ������������ ������
template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:
  TDynamicVector(size_t size = 1) : sz(size);
  TDynamicVector(T* arr, size_t s) : sz(s);
  TDynamicVector(const TDynamicVector& v);
  TDynamicVector(TDynamicVector&& v) noexcept;
  ~TDynamicVector();
  TDynamicVector& operator=(const TDynamicVector& v);
  TDynamicVector& operator=(TDynamicVector&& v) noexcept;

  size_t size() const noexcept;

  // ����������
  T& operator[](size_t ind);
  const T& operator[](size_t ind) const;
  // ���������� � ���������
  T& at(size_t ind);
  const T& at(size_t ind) const;

  // ���������
  bool operator==(const TDynamicVector& v) const noexcept;
  bool operator!=(const TDynamicVector& v) const noexcept;

  // ��������� ��������
  TDynamicVector operator+(T val);
  TDynamicVector operator-(T val);
  TDynamicVector operator*(T val);

  // ��������� ��������
  TDynamicVector operator+(const TDynamicVector& v);
  TDynamicVector operator-(const TDynamicVector& v);
  T operator*(const TDynamicVector& v) noexcept(noexcept(T()));

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept;

  // ����/�����
  friend istream& operator>>(istream& istr, TDynamicVector& v);
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v);
};