Name: libewf
Version: 20160424
Release: 1
Summary: Library to access the Expert Witness Compression Format (EWF)
Group: System Environment/Libraries
License: LGPL
Source: %{name}-%{version}.tar.gz
URL: https://github.com/libyal/libewf/
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)
Requires:          openssl          zlib
BuildRequires:          openssl-devel          zlib-devel

%description
libewf is a library to access the Expert Witness Compression Format (EWF).
libewf allows you to read media information of EWF files in the SMART (EWF-S01)
format and the EnCase (EWF-E01, EWF-L01, EWF2-Ex01 and EWF2-Lx01) formats.
Supports files created by EnCase 1 to 7, linen 5 to 7 and FTK Imager.

%package static
Summary: Library to access the Expert Witness Compression Format (EWF)
Group: Development/Libraries
Requires:          openssl         
BuildRequires:          openssl-devel          zlib-devel zlib-static

%description static
Static library version of libewf

%package devel
Summary: Header files and libraries for developing applications for libewf
Group: Development/Libraries
Requires: libewf = %{version}-%{release}

%description devel
Header files and libraries for developing applications for libewf.

%package tools
Summary: Several tools for reading and writing EWF files
Group: Applications/System
Requires: libewf = %{version}-%{release}  fuse-libs    libuuid
BuildRequires: byacc flex  fuse-devel    libuuid-devel

%description tools
Several tools for reading and writing EWF files.
It contains tools to acquire, export, query and verify EWF files.

%package python
Summary: Python 2 bindings for libewf
Group: System Environment/Libraries
Requires: libewf = %{version}-%{release} python
BuildRequires: python-devel

%description python
Python 2 bindings for libewf

%package python3
Summary: Python 3 bindings for libewf
Group: System Environment/Libraries
Requires: libewf = %{version}-%{release} python3
BuildRequires: python3-devel

%description python3
Python 3 bindings for libewf

%prep
%setup -q

%build
%configure --prefix=/usr --libdir=%{_libdir} --mandir=%{_mandir} --enable-python2 --enable-python3
make %{?_smp_mflags}

%install
rm -rf %{buildroot}
%make_install

%clean
rm -rf %{buildroot}

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files
%defattr(644,root,root,755)
%doc AUTHORS COPYING NEWS README
%attr(755,root,root) %{_libdir}/*.so.*

%files static
%defattr(644,root,root,755)
%doc AUTHORS COPYING NEWS README
%attr(755,root,root) %{_libdir}/*.a

%files devel
%defattr(644,root,root,755)
%doc AUTHORS COPYING NEWS README ChangeLog
%{_libdir}/*.la
%{_libdir}/*.so
%{_libdir}/pkgconfig/libewf.pc
%{_includedir}/*
%{_mandir}/man3/*

%files tools
%defattr(644,root,root,755)
%doc AUTHORS COPYING NEWS README
%attr(755,root,root) %{_bindir}/ewfacquire
%attr(755,root,root) %{_bindir}/ewfacquirestream
%attr(755,root,root) %{_bindir}/ewfexport
%attr(755,root,root) %{_bindir}/ewfinfo
%attr(755,root,root) %{_bindir}/ewfmount
%attr(755,root,root) %{_bindir}/ewfrecover
%attr(755,root,root) %{_bindir}/ewfverify
%{_mandir}/man1/*

%files python
%defattr(644,root,root,755)
%doc AUTHORS COPYING NEWS README
%{_libdir}/python2*/site-packages/*.a
%{_libdir}/python2*/site-packages/*.la
%{_libdir}/python2*/site-packages/*.so

%files python3
%defattr(644,root,root,755)
%doc AUTHORS COPYING NEWS README
%{_libdir}/python3*/site-packages/*.a
%{_libdir}/python3*/site-packages/*.la
%{_libdir}/python3*/site-packages/*.so

### Exclude expirimental files ###
%exclude %{_bindir}/ewfdebug

%changelog
* Mon Apr 25 2016 Joachim Metz <joachim.metz@gmail.com> 20160424-1
- Auto-generated

