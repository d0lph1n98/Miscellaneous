#!/usr/bin/python
import requests
import json

email = ''
password = ''

# thanks :D - https://github.com/swimlane/python-office365
BASE_URL = 'https://outlook.office365.com/api/v1.0/me'
SEND_URL = BASE_URL + '/sendmail'
MAILBOX_URL = BASE_URL + '/folders/{folder_id}/messages'
MESSAGE_URL = BASE_URL + '/messages/{id}'
ALL_MESSAGE_URL = BASE_URL + '/messages'

ATTACHMENT_URL = MESSAGE_URL + '/attachments'
REPLY_URL = MESSAGE_URL+'/reply'
REPLY_ALL_URL = MESSAGE_URL+'/replyall'
FORWARD_URL = MESSAGE_URL+'/forward'

class Office365:
    def __init__(self):
        self.auth = (email, password)

    def pull(self, url):
        try:
            res = requests.get(url, auth=self.auth)
        except Exception as e:
            return e
        return res.json()

    def list(self, url, count):
        try:
            res = requests.get(url + '?$top=' + count, auth=self.auth)
        except Exception as e:
            return e
        return res.json()

    def select(self, url, params):
        try:
            res = requests.get(url + '?$select=' + params, auth=self.auth)
        except Exception as e:
            return e
        return res.json()

    def orderby(self, url, params):
        try:
            res = requests.get(url + '?$orderby=' + params, auth=self.auth)
        except Exception as e:
            return e
        return res.json()

    def filter(self, url, params):
        try:
            res = requests.get(url + '?$filter=' + params, auth=self.auth)
        except Exception as e:
            return e
        return res.json()

    def count(self, url, params):
        try:
            res = requests.get(url + '/$count?$filter=' + params, auth=self.auth)
        except Exception as e:
            return e
        return res.json()

    def search_text(self, url, text):
        try:
            res = requests.get(url + '?$search="search:' + text + '"', auth=self.auth)
        except Exception as e:
            return e
        return res.json()

    def search_from(self, url, text):
        try:
            res = requests.get(url + '?$search="from:' + text + '"', auth=self.auth)
        except Exception as e:
            return e
        return res.json()

    def search_attachment(self, url, text):
        try:
            res = requests.get(url + '?$search="attachment:' + text + '"', auth=self.auth)
        except Exception as e:
            return e
        return res.json()

    def search_bcc(self, url, text):
        try:
            res = requests.get(url + '?$search="bcc:' + text + '"', auth=self.auth)
        except Exception as e:
            return e
        return res.json()

    def search_body(self, url, text):
        try:
            res = requests.get(url + '?$search="body:' + text + '"', auth=self.auth)
        except Exception as e:
            return e
        return res.json()

    def search_category(self, url, text):
        try:
            res = requests.get(url + '?$search="category:' + text + '"', auth=self.auth)
        except Exception as e:
            return e
        return res.json()

    def search_cc(self, url, text):
        try:
            res = requests.get(url + '?$search="cc:' + text + '"', auth=self.auth)
        except Exception as e:
            return e
        return res.json()

    def search_hasattachment(self, url, text):
        try:
            res = requests.get(url + '?$search="has:' + text + '"', auth=self.auth)
        except Exception as e:
            return e
        return res.json()

    def search_participants(self, url, text):
        try:
            res = requests.get(url + '?$search="participants:' + text + '"', auth=self.auth)
        except Exception as e:
            return e
        return res.json()

    def search_received(self, url, text):
        try:
            res = requests.get(url + '?$search="received:' + text + '"', auth=self.auth)
        except Exception as e:
            return e
        return res.json()

    def search_sender(self, url, text):
        try:
            res = requests.get(url + '?$search="sender:' + text + '"', auth=self.auth)
        except Exception as e:
            return e
        return res.json()

    def search_subject(self, url, text):
        try:
            res = requests.get(url + '?$search="subject:' + text + '"', auth=self.auth)
        except Exception as e:
            return e
        return res.json()

    def search_to(self, url, text):
        try:
            res = requests.get(url + '?$search="to:' + text + '"', auth=self.auth)
        except Exception as e:
            return e
        return res.json()

    def search(self, url, text):
        try:
            res = requests.get(url + '?$search="' + text + '"', auth=self.auth)
        except Exception as e:
            return e
        return res.json()

    def user_info(self):
        info = self.pull(BASE_URL)
        print 'Name:', info['DisplayName']
        print '@odata.id:', info['@odata.id']
        print '@odata.context', info['@odata.context']
        print 'Alias:', info['Alias']
        print 'MailboxGuid', info['MailboxGuid']
        print 'Id:', info['Id']

if __name__ == '__main__':
    ofs = Office365()
    data = ofs.filter(ALL_MESSAGE_URL, 'IsRead eq false')

    print data['value'][0]['Body']['Content']
