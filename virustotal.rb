class VirusTotal
    def initialize()
        require 'json'
        require 'rest-client'
        @key = '1e880dba3929c9961b285a58c92964539a45f4c0c964b864706e730c82bd5460'
    end

    def IpScan(ip_src)
        res = RestClient.get('https://www.virustotal.com/vtapi/v2/ip-address/report', {:params => {:ip => ip_src, :key => @key }})
        
        begin
            output = JSON.parse(res)
            output = output['detected_urls'].count

            if output > 0
                return TRUE
            else
                return FALSE
            end 
        rescue Exception => e
            p e.message
        end 
    end 

    def FileScan(file)
        res = RestClient.post('https://www.virustotal.com/vtapi/v2/file/scan',
                              :key => @key,
                              :file => File.new(file, 'r'),
                              :multipart => true)

        output = JSON.parse(res)
        scan_id = output['scan_id'].gsub(/\s|"|'/, '')

        res = RestClient.post('https://www.virustotal.com/vtapi/v2/file/report',
                              :resource => scan_id,
                              :key => @key)

        output = JSON.parse(res)
        output = output['positives']

        if output.nil?
            say 'Resource is queued'
        else 
            begin
                if output > 0
                    return TRUE
                else 
                    return FALSE
                end 
            rescue Exception => e
                p e.message
            end 
        end
    end 
end 
