try:
    from lxml import etree
except ImportError:
    import xml.etree.ElementTree as etree
    print("test import exception")
