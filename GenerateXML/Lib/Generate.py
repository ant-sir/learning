'''
Created on 2015年6月16日

@author: zyl
'''

class Case():
    def __init__(self, wavname, lan, partid, dialogid, eos, tag):
        self.name       = wavname
        self.language   = lan
        self.partid     = partid
        self.dialogid   = dialogid
        self.eos        = eos
        self.tag        = tag


class Generate(object):
    '''
    Generate XML, need root dir name.
    '''

    def __init__(self, folder, state):
        '''
        Need a folder name as the root dir.
        '''
        self.folder = folder
        self.case_list = []
        self.stat = state
        
    def GetWavEos(self, file):
        if self.stat == 2:
            pass
    
    def GetWavTag(self):
        pass
    

    def GetPartId(self):
        pass
    
    
    def GetDialogId(self):
        pass
    
    
    def GenerateCase(self):
        '''
        rootdir
            |----eng
            |    |-->XXX.wav
            |    |-->XXX.wav
            |    |-->XXX.wav
            |----enu
            |    |-->XXX.wav
            |    |-->XXX.wav
        '''
        import os
        for parent, _, filenames in os.walk(self.folder):
            for filename in filenames:
                if filename.endswith('.wav'):
                    self.case_list.append(Case(filename, os.path.split(parent)[1],
                                               self.GetPartId(),
                                               self.GetDialogId(),
                                               self.GetWavEos(os.path.join(parent, filename)),
                                               self.GetWavTag()))
    def Save(self, xml_name):
        '''
        Save xml
        '''
        from lxml import etree
        file = open(xml_name, mode='wb')
        root = etree.Element("test")
        for case in self.case_list:
            child_case = etree.SubElement(root, "case")
            etree.SubElement(child_case, "lang").text = case.language
            etree.SubElement(child_case, "party_id").text = case.partid
            etree.SubElement(child_case, "dialog_id").text = case.dialogid
            etree.SubElement(child_case, "filename").text = case.name
            etree.SubElement(child_case, "expect_result").text = case.tag
            etree.SubElement(child_case, "eos_time").text = case.eos
        file.write(etree.tostring(root, pretty_print=True))
    