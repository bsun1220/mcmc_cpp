from pybind11.setup_helpers import Pybind11Extension
from setuptools import setup

__version__ = "0.0.1"

ext_modules = [
    Pybind11Extension("polywalk",
        ["src/main.cpp"],
        # Example: passing in the version to the compiled code
        define_macros = [('VERSION_INFO', __version__)],
        ),
]

setup(
    name="polywalk",
    version=__version__,
    author="Benny Sun",
    author_email="bys7@duke.edu",
    url="https://github.com/bsun1220",
    description="Uniform Barrier Random Walk on Polytopes",
    long_description="",
    ext_modules=ext_modules
    # Currently, build_ext only provides an optional "highest supported C++
    # level" feature, but in the future it may provide more features.
    zip_safe=False,
    python_requires=">=3.7",
)