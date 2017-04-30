function pingTest()
    s = setup();
    flag = 0;
    while flag == 0
        msg = fgetl(s); % get message from Arduino
        fprintf(msg);
        fwrite(s, 'received'); % acknowledge the message
        flag = strcmp('exit', msg(1:end-1)); % check for exit flag
    end
    exit(s);
end

function s = setup()    
    s = serial('COM12', 'BAUD', 115200);
    fopen(s);    
end

function exit(s)
    fclose(s);
    delete(s);
end