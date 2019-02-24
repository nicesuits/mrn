[%bs.raw {|require('./IssueTable.css')|}];

let component = ReasonReact.statelessComponent("IssueTable");

let make = (~issues, _children) => {
  ...component,
  render: _self => {
    <table>
      <thead>
        <tr>
          <th className="borderedStyle"> {ReasonReact.string("Id")} </th>
          <th className="borderedStyle"> {ReasonReact.string("Status")} </th>
          <th className="borderedStyle"> {ReasonReact.string("Owner")} </th>
          <th className="borderedStyle">
            {ReasonReact.string("Created On")}
          </th>
          <th className="borderedStyle"> {ReasonReact.string("Effort")} </th>
          <th className="borderedStyle">
            {ReasonReact.string("Completed On")}
          </th>
          <th className="borderedStyle"> {ReasonReact.string("Title")} </th>
        </tr>
      </thead>
      <tbody>
        {ReasonReact.array(
           Array.of_list(
             List.map(
               (issue: IssueType.issue) =>
                 <IssueRow key={string_of_int(issue.id)} issue />,
               issues,
             ),
           ),
         )}
      </tbody>
    </table>;
  },
};