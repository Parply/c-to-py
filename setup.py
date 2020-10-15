from distutils.core import setup, Extension

module1 = Extension('rainbowpalette',
                    include_dirs=['/usr/include/python3.8'],
                    libraries=['fopenmp'],
                    sources = ['rainbowpalettepython.cpp'])

setup (name = 'RainbowPalette',
       version = '1.0',
       description = 'Makes a rainbow palette',
       ext_modules = [module1])
